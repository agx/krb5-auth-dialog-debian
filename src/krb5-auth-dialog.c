/*
 * Copyright (C) 2004,2005,2006 Red Hat, Inc.
 * Authored by Christopher Aillon <caillon@redhat.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2, or (at your option)
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.	See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 *
 */

#include "config.h"

#include <stdlib.h>
#include <time.h>
#include <krb5.h>
#include <stdio.h>
#include <sys/wait.h>
#include <string.h>
#include <gtk/gtk.h>
#include <glib/gi18n.h>
#include <glade/glade.h>

#include "gtksecentry.h"
#include "secmem-util.h"
#include "memory.h"

#include "krb5-auth-dialog.h"
#include "krb5-auth-applet.h"
#include "krb5-auth-gconf.h"
#include "krb5-auth-dbus.h"

#ifdef ENABLE_NETWORK_MANAGER
#include <libnm_glib.h>
#endif

static krb5_context kcontext;
static krb5_principal kprincipal;
static krb5_timestamp creds_expiry;
static krb5_timestamp canceled_creds_expiry;
static gboolean canceled;
static gboolean invalid_password;
static gboolean always_run;

static int grab_credentials (Krb5AuthApplet* applet, gboolean renewable);
static gboolean get_tgt_from_ccache (krb5_context context, krb5_creds *creds);

/* YAY for different Kerberos implementations */
static int
get_cred_forwardable(krb5_creds *creds)
{
#if defined(HAVE_KRB5_CREDS_TICKET_FLAGS) && defined(TKT_FLG_FORWARDABLE)
	return creds->ticket_flags & TKT_FLG_FORWARDABLE;
#elif defined(HAVE_KRB5_CREDS_FLAGS_B_FORWARDABLE)
	return creds->flags.b.forwardable;
#elif defined(HAVE_KRB5_CREDS_FLAGS) && defined(KDC_OPT_FORWARDABLE)
	return creds->flags & KDC_OPT_FORWARDABLE;
#endif
}

static int
get_cred_renewable(krb5_creds *creds)
{
#if defined(HAVE_KRB5_CREDS_TICKET_FLAGS) && defined(TKT_FLG_RENEWABLE)
	return creds->ticket_flags & TKT_FLG_RENEWABLE;
#elif defined(HAVE_KRB5_CREDS_FLAGS_B_RENEWABLE)
	return creds->flags.b.renewable;
#elif defined(HAVE_KRB5_CREDS_FLAGS) && defined(KDC_OPT_RENEWABLE)
	return creds->flags & KDC_OPT_RENEWABLE;
#endif
}

static krb5_error_code
get_renewed_creds(krb5_context context,
                  krb5_creds *creds,
                  krb5_principal client,
                  krb5_ccache ccache,
                  char *in_tkt_service)
{
#ifdef HAVE_KRB5_GET_RENEWED_CREDS
	return krb5_get_renewed_creds (context, creds, client, ccache, in_tkt_service);
#else
	return 1; /* XXX is there something better to return? */
#endif
}

static int
get_cred_proxiable(krb5_creds *creds)
{
#if defined(HAVE_KRB5_CREDS_TICKET_FLAGS) && defined(TKT_FLG_PROXIABLE)
	return creds->ticket_flags & TKT_FLG_PROXIABLE;
#elif defined(HAVE_KRB5_CREDS_FLAGS_B_PROXIABLE)
	return creds->flags.b.proxiable;
#elif defined(HAVE_KRB5_CREDS_FLAGS) && defined(KDC_OPT_PROXIABLE)
	return creds->flags & KDC_OPT_PROXIABLE;
#endif
}

static size_t
get_principal_realm_length(krb5_principal p)
{
#if defined(HAVE_KRB5_PRINCIPAL_REALM_AS_STRING)
	return strlen(p->realm);
#elif defined(HAVE_KRB5_PRINCIPAL_REALM_AS_DATA)
	return p->realm.length;
#endif
}

static const char *
get_principal_realm_data(krb5_principal p)
{
#if defined(HAVE_KRB5_PRINCIPAL_REALM_AS_STRING)
	return p->realm;
#elif defined(HAVE_KRB5_PRINCIPAL_REALM_AS_DATA)
	return p->realm.data;
#endif
}
/* ***************************************************************** */
/* ***************************************************************** */

static gboolean
credentials_expiring_real (Krb5AuthApplet* applet, gboolean *renewable)
{
	krb5_creds my_creds;
	krb5_timestamp now;
	gboolean retval = FALSE;
	*renewable = FALSE;

	if (!get_tgt_from_ccache (kcontext, &my_creds)) {
		creds_expiry = 0;
		retval = TRUE;
		goto out;
	}

	if (krb5_principal_compare (kcontext, my_creds.client, kprincipal)) {
		krb5_free_principal(kcontext, kprincipal);
		krb5_copy_principal(kcontext, my_creds.client, &kprincipal);
	}
	creds_expiry = my_creds.times.endtime;
	if ((krb5_timeofday(kcontext, &now) == 0) &&
	    (now + applet->pw_prompt_secs > my_creds.times.endtime))
		retval = TRUE;

	/* If our creds are expiring, determine whether they are renewable */
	if (retval && get_cred_renewable(&my_creds) && my_creds.times.renew_till > now) {
		*renewable = TRUE;
	}

	krb5_free_cred_contents (kcontext, &my_creds);

out:
	ka_update_status(applet, creds_expiry);
	return retval;
}


static gchar* minutes_to_expiry_text (int minutes)
{
	gchar *expiry_text;
	gchar *tmp;

	if (minutes > 0) {
		expiry_text = g_strdup_printf (ngettext("Your credentials expire in %d minute",
		                                        "Your credentials expire in %d minutes",
		                                        minutes),
		                               minutes);
	} else {
		expiry_text = g_strdup (_("Your credentials have expired"));
		tmp = g_strdup_printf ("<span foreground=\"red\">%s</span>", expiry_text);
		g_free (expiry_text);
		expiry_text = tmp;
	}

	return expiry_text;
}


static gboolean
krb5_auth_dialog_wrong_label_update_expiry (GtkWidget* label)
{
	int minutes_left;
	krb5_timestamp now;
	gchar *expiry_text;
	gchar *expiry_markup;

	g_return_val_if_fail (label!= NULL, FALSE);

	if (krb5_timeofday(kcontext, &now) != 0) {
		return TRUE;
	}

	minutes_left = (creds_expiry - now) / 60;
	expiry_text = minutes_to_expiry_text (minutes_left);

	expiry_markup = g_strdup_printf ("<span size=\"smaller\" style=\"italic\">%s</span>", expiry_text);
	gtk_label_set_markup (GTK_LABEL (label), expiry_markup);
	g_free (expiry_text);
	g_free (expiry_markup);

	return TRUE;
}


/* Check for things we have to do while the password dialog is open */
static gboolean
krb5_auth_dialog_do_updates(gpointer data) 
{
	Krb5AuthApplet* applet = (Krb5AuthApplet*)data;
	gboolean refreshable;

	g_return_val_if_fail (applet != NULL, FALSE);

	/* Update creds_expiry and close the applet if we got the creds by other means (e.g. kinit) */
	if (!credentials_expiring_real(applet, &refreshable)) {
		KA_DEBUG("PW Dialog persist is %d", applet->pw_dialog_persist);
		if (!applet->pw_dialog_persist)
			gtk_widget_hide(applet->pw_dialog);
	}

	/* Update the expiry information in the dialog */
	krb5_auth_dialog_wrong_label_update_expiry (applet->pw_wrong_label);
	return TRUE;
}


static void
krb5_auth_dialog_setup (Krb5AuthApplet *applet,
                        const gchar *krb5prompt,
                        gboolean hide_password)
{
	GtkWidget *entry;
	GtkWidget *label;
	gchar *wrong_text;
	gchar *wrong_markup;
	gchar *prompt;
	int pw4len;


	if (krb5prompt == NULL) {
		prompt = g_strdup (_("Please enter your Kerberos password."));
	} else {
		/* Kerberos's prompts are a mess, and basically impossible to
		 * translate.  There's basically no way short of doing a lot of
		 * string parsing to translate them.  The most common prompt is
		 * "Password for $uid:".  We special case that one at least.  We
		 * cannot do any of the fancier strings (like challenges),
		 * though. */
		pw4len = strlen ("Password for ");
		if (strncmp (krb5prompt, "Password for ", pw4len) == 0) {
			gchar *uid = (gchar *) (krb5prompt + pw4len);
			prompt = g_strdup_printf (_("Please enter the password for '%s'"), uid);
		} else {
			prompt = g_strdup (krb5prompt);
		}
	}

	/* Clear the password entry field */
	entry = glade_xml_get_widget (applet->pw_xml, "krb5_entry");
	gtk_secure_entry_set_text (GTK_SECURE_ENTRY (entry), "");

	/* Use the prompt label that krb5 provides us */
	label = glade_xml_get_widget (applet->pw_xml, "krb5_message_label");
	gtk_label_set_text (GTK_LABEL (label), prompt);

	/* Add our extra message hints, if any */
	wrong_text = NULL;

	if (applet->pw_wrong_label) {
		if (invalid_password) {
			wrong_text = g_strdup (_("The password you entered is invalid"));
		} else {
			krb5_timestamp now;
			int minutes_left;

			if (krb5_timeofday(kcontext, &now) == 0)
				minutes_left = (creds_expiry - now) / 60;
			else
				minutes_left = 0;
			wrong_text = minutes_to_expiry_text (minutes_left);
		}
	}

	if (wrong_text) {
		wrong_markup = g_strdup_printf ("<span size=\"smaller\" style=\"italic\">%s</span>", wrong_text);
		gtk_label_set_markup (GTK_LABEL (applet->pw_wrong_label), wrong_markup);
		g_free(wrong_text);
		g_free(wrong_markup);
	} else {
		gtk_label_set_text (GTK_LABEL (applet->pw_wrong_label), "");
	}
	g_free (prompt);
}


static krb5_error_code
auth_dialog_prompter (krb5_context ctx,
                      void *data,
                      const char *name,
                      const char *banner,
                      int num_prompts,
                      krb5_prompt prompts[])
{
	Krb5AuthApplet* applet = (Krb5AuthApplet*)data;
	krb5_error_code errcode;
	int i;

	errcode = KRB5_LIBOS_CANTREADPWD;
	canceled = FALSE;
	canceled_creds_expiry = 0;

	for (i = 0; i < num_prompts; i++) {
		const gchar *password = NULL;
		int password_len = 0;
		int response;
		guint32 source_id = 0;

		GtkWidget *entry;

		errcode = KRB5_LIBOS_CANTREADPWD;

		krb5_auth_dialog_setup (applet, (gchar *) prompts[i].prompt, prompts[i].hidden);
		entry = glade_xml_get_widget(applet->pw_xml, "krb5_entry");
		gtk_widget_grab_focus(entry);

		source_id = g_timeout_add_seconds (5, (GSourceFunc)krb5_auth_dialog_do_updates, applet);
		response = gtk_dialog_run (GTK_DIALOG (applet->pw_dialog));
		switch (response)
		{
			case GTK_RESPONSE_OK:
				password = gtk_secure_entry_get_text (GTK_SECURE_ENTRY (entry));
				password_len = strlen (password);
				errcode = 0;
				break;
			case GTK_RESPONSE_CANCEL:
				canceled = TRUE;
				break;
			case GTK_RESPONSE_NONE:
			case GTK_RESPONSE_DELETE_EVENT:
				break;
			default:
				g_warning ("Unknown Response: %d", response);
				g_assert_not_reached ();
		}

		g_source_remove (source_id);

		prompts[i].reply->data = (char *) password;
		prompts[i].reply->length = password_len;
	}

	/* Reset this, so we know the next time we get a TRUE value, it is accurate. */
	gtk_widget_hide (applet->pw_dialog);
	invalid_password = FALSE;

	return errcode;
}

static gboolean is_online = TRUE;

#ifdef ENABLE_NETWORK_MANAGER
static void
network_state_cb (libnm_glib_ctx *context,
                  gpointer data)
{
	gboolean *online = (gboolean*) data;

	libnm_glib_state state;

	state = libnm_glib_get_network_state (context);

	switch (state)
	{
		case LIBNM_NO_DBUS:
		case LIBNM_NO_NETWORKMANAGER:
		case LIBNM_INVALID_CONTEXT:
			/* do nothing */
			break;
		case LIBNM_NO_NETWORK_CONNECTION:
			*online = FALSE;
			break;
		case LIBNM_ACTIVE_NETWORK_CONNECTION:
			*online = TRUE;
			break;
	}
}
#endif


static gboolean
credentials_expiring (gpointer *data)
{
	int retval;
	gboolean give_up;
	gboolean renewable;
	Krb5AuthApplet* applet = (Krb5AuthApplet*) data;

	KA_DEBUG("Checking expiry: %d", applet->pw_prompt_secs);
	if (credentials_expiring_real (applet, &renewable) && is_online) {
		give_up = canceled && (creds_expiry == canceled_creds_expiry);
		if (!give_up) {
			do {
				retval = grab_credentials (applet, renewable);
				give_up = canceled &&
					  (creds_expiry == canceled_creds_expiry);
			} while ((retval != 0) && 
			         (retval != KRB5_REALM_CANT_RESOLVE) &&
			         (retval != KRB5_KDC_UNREACH) &&
				 invalid_password &&
			         !give_up);
		}
	}
	ka_update_status(applet, creds_expiry);
	return TRUE;
}


static void
set_options_using_creds(const Krb5AuthApplet* applet,
			krb5_context context,
			krb5_creds *creds,
			krb5_get_init_creds_opt *opts)
{
	krb5_deltat renew_lifetime;
	int flag;

	flag = get_cred_forwardable(creds) != 0;
	krb5_get_init_creds_opt_set_forwardable(opts, flag);
	flag = get_cred_proxiable(creds) != 0;
	krb5_get_init_creds_opt_set_proxiable(opts, flag);
	flag = get_cred_renewable(creds) != 0;
	if (flag && (creds->times.renew_till > creds->times.starttime)) {
		renew_lifetime = creds->times.renew_till -
				 creds->times.starttime;
		krb5_get_init_creds_opt_set_renew_life(opts,
						       renew_lifetime);
	}
	if (creds->times.endtime >
	    creds->times.starttime + applet->pw_prompt_secs) {
		krb5_get_init_creds_opt_set_tkt_life(opts,
					 	     creds->times.endtime -
						     creds->times.starttime);
	}
	/* This doesn't do a deep copy -- fix it later. */
	/* krb5_get_init_creds_opt_set_address_list(opts, creds->addresses); */
}

static int
grab_credentials (Krb5AuthApplet* applet, gboolean renewable)
{
	krb5_error_code retval;
	krb5_creds my_creds;
	krb5_ccache ccache;
	krb5_get_init_creds_opt opts;

	memset(&my_creds, 0, sizeof(my_creds));

	if (kprincipal == NULL) {
		retval = krb5_parse_name(kcontext, applet->principal,
					 &kprincipal);
		if (retval) {
			return retval;
		}
	}

	retval = krb5_cc_default (kcontext, &ccache);
	if (retval)
		return retval;

	krb5_get_init_creds_opt_init (&opts);
	if (get_tgt_from_ccache (kcontext, &my_creds)) {
		set_options_using_creds (applet, kcontext, &my_creds, &opts);
		creds_expiry = my_creds.times.endtime;

		if (renewable) {
			retval = get_renewed_creds (kcontext, &my_creds, kprincipal, ccache, NULL);

			/* If we succeeded in renewing the credentials, we store it. */
			if (retval == 0) {
				goto store;
			}
			/* Else, try to get new credentials, so just fall through */
		}
		krb5_free_cred_contents (kcontext, &my_creds);
	} else {
		creds_expiry = 0;
	}

	retval = krb5_get_init_creds_password(kcontext, &my_creds, kprincipal,
	                                      NULL, auth_dialog_prompter, applet,
	       	                              0, NULL, &opts);
	if (canceled) {
		canceled_creds_expiry = creds_expiry;
	}
	if (retval) {
		switch (retval) {
			case KRB5KDC_ERR_PREAUTH_FAILED:
			case KRB5KRB_AP_ERR_BAD_INTEGRITY:
				/* Invalid password, try again. */
				invalid_password = TRUE;
				goto out;
			default:
				break;
		}
		goto out;
	}

store:
	retval = krb5_cc_initialize(kcontext, ccache, kprincipal);
	if (retval) {
		goto out;
	}

	retval = krb5_cc_store_cred(kcontext, ccache, &my_creds);
	if (retval) {
		goto out;
	}

	creds_expiry = my_creds.times.endtime;
out:
	krb5_free_cred_contents (kcontext, &my_creds);
	krb5_cc_close (kcontext, ccache);

	return retval;
}

static gboolean
get_tgt_from_ccache (krb5_context context, krb5_creds *creds)
{
	krb5_ccache ccache;
	krb5_creds mcreds;
	krb5_principal principal, tgt_principal;
	gboolean ret;

	memset(&ccache, 0, sizeof(ccache));
	ret = FALSE;
	if (krb5_cc_default(context, &ccache) == 0) {
		memset(&principal, 0, sizeof(principal));
		if (krb5_cc_get_principal(context, ccache, &principal) == 0) {
			memset(&tgt_principal, 0, sizeof(tgt_principal));
			if (krb5_build_principal_ext(context, &tgt_principal,
			                             get_principal_realm_length(principal),
			                             get_principal_realm_data(principal),
			                             KRB5_TGS_NAME_SIZE,
			                             KRB5_TGS_NAME,
			                             get_principal_realm_length(principal),
			                             get_principal_realm_data(principal),
			                             0) == 0) {
				memset(creds, 0, sizeof(*creds));
				memset(&mcreds, 0, sizeof(mcreds));
				mcreds.client = principal;
				mcreds.server = tgt_principal;
				if (krb5_cc_retrieve_cred(context, ccache,
				                          0,
				                          &mcreds,
				                          creds) == 0) {
					ret = TRUE;
				} else {
					memset(creds, 0, sizeof(*creds));
				}
				krb5_free_principal(context, tgt_principal);
			}
			krb5_free_principal(context, principal);
		}
		krb5_cc_close(context, ccache);
	}
	return ret;
}

static gboolean
using_krb5()
{
	krb5_error_code err;
	gboolean have_tgt = FALSE;
	krb5_creds creds;

	err = krb5_init_context(&kcontext);
	if (err) {
		return TRUE;
	}

	have_tgt = get_tgt_from_ccache(kcontext, &creds);
	if (have_tgt) {
		krb5_copy_principal(kcontext, creds.client, &kprincipal);
		krb5_free_cred_contents (kcontext, &creds);
	}

	return have_tgt;
}


void
ka_destroy_cache (GtkMenuItem  *menuitem, gpointer data)
{
	Krb5AuthApplet* applet = (Krb5AuthApplet*) data;
	krb5_ccache  ccache;
	const char* cache;
	krb5_error_code ret;
	gboolean renewable;

	cache = krb5_cc_default_name(kcontext);
	ret =  krb5_cc_resolve(kcontext, cache, &ccache);
	ret = krb5_cc_destroy (kcontext, ccache);

	credentials_expiring_real(applet, &renewable);
}


static void 
ka_error_dialog(int err)
{
	const char* msg = error_message(err);
	GtkWidget *dialog = gtk_message_dialog_new (NULL,
		      		GTK_DIALOG_DESTROY_WITH_PARENT,
		      		GTK_MESSAGE_ERROR,
		      		GTK_BUTTONS_CLOSE,
		      		_("Couldn't acquire kerberos ticket: '%s'"), msg);
 	gtk_dialog_run (GTK_DIALOG (dialog));
	gtk_widget_destroy (dialog);
}


/* this is done on leftclick, update the tooltip immediately */
void
ka_grab_credentials (Krb5AuthApplet* applet)
{
	int retval;
	gboolean renewable, retry;

	applet->pw_dialog_persist = TRUE;
	do {
		retry = TRUE;
		retval = grab_credentials (applet, FALSE);
		switch (retval) {
		    case KRB5KRB_AP_ERR_BAD_INTEGRITY:
			    retry = TRUE;
			    break;
		    case 0: /* success */
		    case KRB5_LIBOS_CANTREADPWD: /* canceled */
		    	    retry = FALSE;
			    break;
		    case KRB5KDC_ERR_C_PRINCIPAL_UNKNOWN:
		    default:
			    ka_error_dialog(retval);
			    retry = FALSE;
			    break;
		}
	} while(retry);

	applet->pw_dialog_persist = FALSE;
	credentials_expiring_real(applet, &renewable);
}


static GtkWidget*
ka_create_gtk_secure_entry (GladeXML *xml, gchar *func_name, gchar *name,
				gchar *s1, gchar *s2, gint i1, gint i2,
				gpointer user_data)
{
	GtkWidget* entry = NULL;

	if (!strcmp(name, "krb5_entry")) {
		entry = gtk_secure_entry_new ();
		gtk_secure_entry_set_activates_default(GTK_SECURE_ENTRY(entry), TRUE);
		gtk_widget_show (entry);
	} else {
		g_warning("Don't know anything about widget %s", name);
	}
	return entry;
}


static void 
ka_secmem_init ()
{
	/* Initialize secure memory.  1 is too small, so the default size
	will be used.  */
	secmem_init (1);
	secmem_set_flags (SECMEM_WARN);
	drop_privs ();

	if (atexit (secmem_term))
		g_error("Couln't register atexit handler");
}


int
main (int argc, char *argv[])
{
	Krb5AuthApplet *applet;
	GOptionContext *context;
	GError *error = NULL;

	guint status = 0;
	gboolean run_auto = FALSE, run_always = FALSE;

	const char *help_msg = "Run '" PACKAGE " --help' to see a full list of available command line options";
	const GOptionEntry options [] = {
		{"auto", 'a', 0, G_OPTION_ARG_NONE, &run_auto,
		 	"Only run if an initialized ccache is found (default)", NULL},
		{"always", 'A', 0, G_OPTION_ARG_NONE, &run_always,
		 	"Always run", NULL},
  		{ NULL, 0, 0, G_OPTION_ARG_NONE, NULL, NULL, NULL }
	};

#ifdef ENABLE_NETWORK_MANAGER
	libnm_glib_ctx *nm_context;
	guint32 nm_callback_id;	
#endif
	context = g_option_context_new ("- Kerberos 5 credential checking");
	g_option_context_add_main_entries (context, options, NULL);
	g_option_context_add_group (context, gtk_get_option_group (TRUE));
	g_option_context_parse (context, &argc, &argv, &error);
	if (error) {
		g_print ("%s\n%s\n",
			 error->message,
			 help_msg);
		g_error_free (error);
		return 1;
	}
	textdomain(PACKAGE);
	bind_textdomain_codeset(PACKAGE, "UTF-8");
	bindtextdomain(PACKAGE, LOCALE_DIR);
	ka_secmem_init();

	if(!ka_dbus_connect (&status))
		exit(status);

	if (run_always && !run_auto) {
		always_run = TRUE;
	}
	if (using_krb5 () || always_run) {
		applet = ka_create_applet();
		if (!applet)
			return 1;
		if (!ka_gconf_init(applet, argc, argv))
			return 1;

		/* setup the pw dialog */
		glade_set_custom_handler (&ka_create_gtk_secure_entry, NULL);
		applet->pw_xml = glade_xml_new (GLADEDIR "krb5-auth-dialog.glade", NULL, NULL);
		applet->pw_wrong_label = glade_xml_get_widget (applet->pw_xml, "krb5_wrong_label");
		applet->pw_dialog = glade_xml_get_widget (applet->pw_xml, "krb5_dialog");

		g_set_application_name (_("Network Authentication"));
		gtk_window_set_default_icon_name(applet->icons[1]);

#ifdef ENABLE_NETWORK_MANAGER
		nm_context = libnm_glib_init ();
		if (!nm_context) {
			g_warning ("Could not initialize libnm_glib");
		} else {
			nm_callback_id = libnm_glib_register_callback (nm_context, network_state_cb, &is_online, NULL);
			if (nm_callback_id == 0) {
				libnm_glib_shutdown (nm_context);
				nm_context = NULL;

				g_warning ("Could not connect to NetworkManager, connection status will not be managed!");
			}
		}
#endif /* ENABLE_NETWORK_MANAGER */

		if (credentials_expiring ((gpointer)applet)) {
			g_timeout_add_seconds (CREDENTIAL_CHECK_INTERVAL, (GSourceFunc)credentials_expiring, applet);
		}
		gtk_main ();
	}

	return 0;
}
