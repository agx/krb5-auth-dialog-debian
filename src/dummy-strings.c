/* Generated by hand via "cd etpo; make update-etpo" from /tmp/krb5-1.6.dfsg.4~beta1/ */
#include <glib/gi18n.h>


const char *dummy[] = {
	/* Translators: files from dummy-strings.c are *all* possible errors
           returned from Kerberos (since Kerberos itself doesn't handle i18n). If in
	   doubt please translate strings from files starting with krb5-auth
	   first since these are the ones the user will see in any case. */
	N_("ASN.1 failed call to system time library"),	/* asn1_err.et:asn1:ASN1_BAD_TIMEFORMAT */
	N_("ASN.1 structure is missing a required field"),	/* asn1_err.et:asn1:ASN1_MISSING_FIELD */
	N_("ASN.1 unexpected field number"),	/* asn1_err.et:asn1:ASN1_MISPLACED_FIELD */
	N_("ASN.1 type numbers are inconsistent"),	/* asn1_err.et:asn1:ASN1_TYPE_MISMATCH */
	N_("ASN.1 value too large"),	/* asn1_err.et:asn1:ASN1_OVERFLOW */
	N_("ASN.1 encoding ended unexpectedly"),	/* asn1_err.et:asn1:ASN1_OVERRUN */
	N_("ASN.1 identifier doesn't match expected value"),	/* asn1_err.et:asn1:ASN1_BAD_ID */
	N_("ASN.1 length doesn't match expected value"),	/* asn1_err.et:asn1:ASN1_BAD_LENGTH */
	N_("ASN.1 badly-formatted encoding"),	/* asn1_err.et:asn1:ASN1_BAD_FORMAT */
	N_("ASN.1 parse error"),	/* asn1_err.et:asn1:ASN1_PARSE_ERROR */
	N_("ASN.1 bad return from gmtime"),	/* asn1_err.et:asn1:ASN1_BAD_GMTIME */
	N_("ASN.1 non-constructed indefinite encoding"),	/* asn1_err.et:asn1:ASN1_MISMATCH_INDEF */
	N_("ASN.1 missing expected EOC"),	/* asn1_err.et:asn1:ASN1_MISSING_EOC */
	N_("No error"),	/* krb5_err.et:krb5:KRB5KDC_ERR_NONE */
	N_("Client's entry in database has expired"),	/* krb5_err.et:krb5:KRB5KDC_ERR_NAME_EXP */
	N_("Server's entry in database has expired"),	/* krb5_err.et:krb5:KRB5KDC_ERR_SERVICE_EXP */
	N_("Requested protocol version not supported"),	/* krb5_err.et:krb5:KRB5KDC_ERR_BAD_PVNO */
	N_("Client's key is encrypted in an old master key"),	/* krb5_err.et:krb5:KRB5KDC_ERR_C_OLD_MAST_KVNO */
	N_("Server's key is encrypted in an old master key"),	/* krb5_err.et:krb5:KRB5KDC_ERR_S_OLD_MAST_KVNO */
	N_("Client not found in Kerberos database"),	/* krb5_err.et:krb5:KRB5KDC_ERR_C_PRINCIPAL_UNKNOWN */
	N_("Server not found in Kerberos database"),	/* krb5_err.et:krb5:KRB5KDC_ERR_S_PRINCIPAL_UNKNOWN */
	N_("Principal has multiple entries in Kerberos database"),	/* krb5_err.et:krb5:KRB5KDC_ERR_PRINCIPAL_NOT_UNIQUE */
	N_("Client or server has a null key"),	/* krb5_err.et:krb5:KRB5KDC_ERR_NULL_KEY */
	N_("Ticket is ineligible for postdating"),	/* krb5_err.et:krb5:KRB5KDC_ERR_CANNOT_POSTDATE */
	N_("Requested effective lifetime is negative or too short"),	/* krb5_err.et:krb5:KRB5KDC_ERR_NEVER_VALID */
	N_("KDC policy rejects request"),	/* krb5_err.et:krb5:KRB5KDC_ERR_POLICY */
	N_("KDC can't fulfill requested option"),	/* krb5_err.et:krb5:KRB5KDC_ERR_BADOPTION */
	N_("KDC has no support for encryption type"),	/* krb5_err.et:krb5:KRB5KDC_ERR_ETYPE_NOSUPP */
	N_("KDC has no support for checksum type"),	/* krb5_err.et:krb5:KRB5KDC_ERR_SUMTYPE_NOSUPP */
	N_("KDC has no support for padata type"),	/* krb5_err.et:krb5:KRB5KDC_ERR_PADATA_TYPE_NOSUPP */
	N_("KDC has no support for transited type"),	/* krb5_err.et:krb5:KRB5KDC_ERR_TRTYPE_NOSUPP */
	N_("Clients credentials have been revoked"),	/* krb5_err.et:krb5:KRB5KDC_ERR_CLIENT_REVOKED */
	N_("Credentials for server have been revoked"),	/* krb5_err.et:krb5:KRB5KDC_ERR_SERVICE_REVOKED */
	N_("TGT has been revoked"),	/* krb5_err.et:krb5:KRB5KDC_ERR_TGT_REVOKED */
	N_("Client not yet valid - try again later"),	/* krb5_err.et:krb5:KRB5KDC_ERR_CLIENT_NOTYET */
	N_("Server not yet valid - try again later"),	/* krb5_err.et:krb5:KRB5KDC_ERR_SERVICE_NOTYET */
	N_("Password has expired"),	/* krb5_err.et:krb5:KRB5KDC_ERR_KEY_EXP */
	N_("Preauthentication failed"),	/* krb5_err.et:krb5:KRB5KDC_ERR_PREAUTH_FAILED */
	N_("Additional pre-authentication required"),	/* krb5_err.et:krb5:KRB5KDC_ERR_PREAUTH_REQUIRED */
	N_("Requested server and ticket don't match"),	/* krb5_err.et:krb5:KRB5KDC_ERR_SERVER_NOMATCH */
	N_("A service is not available that is required to process the request"),	/* krb5_err.et:krb5:KRB5KDC_ERR_SVC_UNAVAILABLE */
	N_("Decrypt integrity check failed"),	/* krb5_err.et:krb5:KRB5KRB_AP_ERR_BAD_INTEGRITY */
	N_("Ticket expired"),	/* krb5_err.et:krb5:KRB5KRB_AP_ERR_TKT_EXPIRED */
	N_("Ticket not yet valid"),	/* krb5_err.et:krb5:KRB5KRB_AP_ERR_TKT_NYV */
	N_("Request is a replay"),	/* krb5_err.et:krb5:KRB5KRB_AP_ERR_REPEAT */
	N_("The ticket isn't for us"),	/* krb5_err.et:krb5:KRB5KRB_AP_ERR_NOT_US */
	N_("Ticket/authenticator don't match"),	/* krb5_err.et:krb5:KRB5KRB_AP_ERR_BADMATCH */
	N_("Clock skew too great"),	/* krb5_err.et:krb5:KRB5KRB_AP_ERR_SKEW */
	N_("Incorrect net address"),	/* krb5_err.et:krb5:KRB5KRB_AP_ERR_BADADDR */
	N_("Protocol version mismatch"),	/* krb5_err.et:krb5:KRB5KRB_AP_ERR_BADVERSION */
	N_("Invalid message type"),	/* krb5_err.et:krb5:KRB5KRB_AP_ERR_MSG_TYPE */
	N_("Message stream modified"),	/* krb5_err.et:krb5:KRB5KRB_AP_ERR_MODIFIED */
	N_("Message out of order"),	/* krb5_err.et:krb5:KRB5KRB_AP_ERR_BADORDER */
	N_("Illegal cross-realm ticket"),	/* krb5_err.et:krb5:KRB5KRB_AP_ERR_ILL_CR_TKT */
	N_("Key version is not available"),	/* krb5_err.et:krb5:KRB5KRB_AP_ERR_BADKEYVER */
	N_("Service key not available"),	/* krb5_err.et:krb5:KRB5KRB_AP_ERR_NOKEY */
	N_("Mutual authentication failed"),	/* krb5_err.et:krb5:KRB5KRB_AP_ERR_MUT_FAIL */
	N_("Incorrect message direction"),	/* krb5_err.et:krb5:KRB5KRB_AP_ERR_BADDIRECTION */
	N_("Alternative authentication method required"),	/* krb5_err.et:krb5:KRB5KRB_AP_ERR_METHOD */
	N_("Incorrect sequence number in message"),	/* krb5_err.et:krb5:KRB5KRB_AP_ERR_BADSEQ */
	N_("Inappropriate type of checksum in message"),	/* krb5_err.et:krb5:KRB5KRB_AP_ERR_INAPP_CKSUM */
	N_("Policy rejects transited path"),	/* krb5_err.et:krb5:KRB5KRB_AP_PATH_NOT_ACCEPTED */
	N_("Response too big for UDP, retry with TCP"),	/* krb5_err.et:krb5:KRB5KRB_ERR_RESPONSE_TOO_BIG */
	N_("Generic error (see e-text)"),	/* krb5_err.et:krb5:KRB5KRB_ERR_GENERIC */
	N_("Field is too long for this implementation"),	/* krb5_err.et:krb5:KRB5KRB_ERR_FIELD_TOOLONG */
	N_("Client not trusted"),	/* krb5_err.et:krb5:KRB5KDC_ERR_CLIENT_NOT_TRUSTED */
	N_("KDC not trusted"),	/* krb5_err.et:krb5:KRB5KDC_ERR_KDC_NOT_TRUSTED */
	N_("Invalid signature"),	/* krb5_err.et:krb5:KRB5KDC_ERR_INVALID_SIG */
	N_("Key parameters not accepted"),	/* krb5_err.et:krb5:KRB5KDC_ERR_DH_KEY_PARAMETERS_NOT_ACCEPTED */
	N_("Certificate mismatch"),	/* krb5_err.et:krb5:KRB5KDC_ERR_CERTIFICATE_MISMATCH */
	N_("Can't verify certificate"),	/* krb5_err.et:krb5:KRB5KDC_ERR_CANT_VERIFY_CERTIFICATE */
	N_("Invalid certificate"),	/* krb5_err.et:krb5:KRB5KDC_ERR_INVALID_CERTIFICATE */
	N_("Revoked certificate"),	/* krb5_err.et:krb5:KRB5KDC_ERR_REVOKED_CERTIFICATE */
	N_("Revocation status unknown"),	/* krb5_err.et:krb5:KRB5KDC_ERR_REVOCATION_STATUS_UNKNOWN */
	N_("Revocation status unavailable"),	/* krb5_err.et:krb5:KRB5KDC_ERR_REVOCATION_STATUS_UNAVAILABLE */
	N_("Client name mismatch"),	/* krb5_err.et:krb5:KRB5KDC_ERR_CLIENT_NAME_MISMATCH */
	N_("KDC name mismatch"),	/* krb5_err.et:krb5:KRB5KDC_ERR_KDC_NAME_MISMATCH */
	N_("Inconsistent key purpose"),	/* krb5_err.et:krb5:KRB5KDC_ERR_INCONSISTENT_KEY_PURPOSE */
	N_("Digest in certificate not accepted"),	/* krb5_err.et:krb5:KRB5KDC_ERR_DIGEST_IN_CERT_NOT_ACCEPTED */
	N_("Checksum must be included"),	/* krb5_err.et:krb5:KRB5KDC_ERR_PA_CHECKSUM_MUST_BE_INCLUDED */
	N_("Digest in signed-data not accepted"),	/* krb5_err.et:krb5:KRB5KDC_ERR_DIGEST_IN_SIGNED_DATA_NOT_ACCEPTED */
	N_("Public key encryption not supported"),	/* krb5_err.et:krb5:KRB5KDC_ERR_PUBLIC_KEY_ENCRYPTION_NOT_SUPPORTED */
	N_("$Id: krb5_err.et 19934 2007-09-13 23:49:00Z tlyu $"),	/* krb5_err.et:krb5:KRB5_ERR_RCSID */
	N_("Invalid flag for file lock mode"),	/* krb5_err.et:krb5:KRB5_LIBOS_BADLOCKFLAG */
	N_("Cannot read password"),	/* krb5_err.et:krb5:KRB5_LIBOS_CANTREADPWD */
	N_("Password mismatch"),	/* krb5_err.et:krb5:KRB5_LIBOS_BADPWDMATCH */
	N_("Password read interrupted"),	/* krb5_err.et:krb5:KRB5_LIBOS_PWDINTR */
	N_("Illegal character in component name"),	/* krb5_err.et:krb5:KRB5_PARSE_ILLCHAR */
	N_("Malformed representation of principal"),	/* krb5_err.et:krb5:KRB5_PARSE_MALFORMED */
	N_("Can't open/find Kerberos configuration file"),	/* krb5_err.et:krb5:KRB5_CONFIG_CANTOPEN */
	N_("Improper format of Kerberos configuration file"),	/* krb5_err.et:krb5:KRB5_CONFIG_BADFORMAT */
	N_("Insufficient space to return complete information"),	/* krb5_err.et:krb5:KRB5_CONFIG_NOTENUFSPACE */
	N_("Invalid message type specified for encoding"),	/* krb5_err.et:krb5:KRB5_BADMSGTYPE */
	N_("Credential cache name malformed"),	/* krb5_err.et:krb5:KRB5_CC_BADNAME */
	N_("Unknown credential cache type"),	/* krb5_err.et:krb5:KRB5_CC_UNKNOWN_TYPE */
	N_("Matching credential not found"),	/* krb5_err.et:krb5:KRB5_CC_NOTFOUND */
	N_("End of credential cache reached"),	/* krb5_err.et:krb5:KRB5_CC_END */
	N_("Request did not supply a ticket"),	/* krb5_err.et:krb5:KRB5_NO_TKT_SUPPLIED */
	N_("Wrong principal in request"),	/* krb5_err.et:krb5:KRB5KRB_AP_WRONG_PRINC */
	N_("Ticket has invalid flag set"),	/* krb5_err.et:krb5:KRB5KRB_AP_ERR_TKT_INVALID */
	N_("Requested principal and ticket don't match"),	/* krb5_err.et:krb5:KRB5_PRINC_NOMATCH */
	N_("KDC reply did not match expectations"),	/* krb5_err.et:krb5:KRB5_KDCREP_MODIFIED */
	N_("Clock skew too great in KDC reply"),	/* krb5_err.et:krb5:KRB5_KDCREP_SKEW */
	N_("Client/server realm mismatch in initial ticket request"),	/* krb5_err.et:krb5:KRB5_IN_TKT_REALM_MISMATCH */
	N_("Program lacks support for encryption type"),	/* krb5_err.et:krb5:KRB5_PROG_ETYPE_NOSUPP */
	N_("Program lacks support for key type"),	/* krb5_err.et:krb5:KRB5_PROG_KEYTYPE_NOSUPP */
	N_("Requested encryption type not used in message"),	/* krb5_err.et:krb5:KRB5_WRONG_ETYPE */
	N_("Program lacks support for checksum type"),	/* krb5_err.et:krb5:KRB5_PROG_SUMTYPE_NOSUPP */
	N_("Cannot find KDC for requested realm"),	/* krb5_err.et:krb5:KRB5_REALM_UNKNOWN */
	N_("Kerberos service unknown"),	/* krb5_err.et:krb5:KRB5_SERVICE_UNKNOWN */
	N_("Cannot contact any KDC for requested realm"),	/* krb5_err.et:krb5:KRB5_KDC_UNREACH */
	N_("No local name found for principal name"),	/* krb5_err.et:krb5:KRB5_NO_LOCALNAME */
	N_("Mutual authentication failed"),	/* krb5_err.et:krb5:KRB5_MUTUAL_FAILED */
	N_("Replay cache type is already registered"),	/* krb5_err.et:krb5:KRB5_RC_TYPE_EXISTS */
	N_("No more memory to allocate (in replay cache code)"),	/* krb5_err.et:krb5:KRB5_RC_MALLOC */
	N_("Replay cache type is unknown"),	/* krb5_err.et:krb5:KRB5_RC_TYPE_NOTFOUND */
	N_("Generic unknown RC error"),	/* krb5_err.et:krb5:KRB5_RC_UNKNOWN */
	N_("Message is a replay"),	/* krb5_err.et:krb5:KRB5_RC_REPLAY */
	N_("Replay I/O operation failed XXX"),	/* krb5_err.et:krb5:KRB5_RC_IO */
	N_("Replay cache type does not support non-volatile storage"),	/* krb5_err.et:krb5:KRB5_RC_NOIO */
	N_("Replay cache name parse/format error"),	/* krb5_err.et:krb5:KRB5_RC_PARSE */
	N_("End-of-file on replay cache I/O"),	/* krb5_err.et:krb5:KRB5_RC_IO_EOF */
	N_("No more memory to allocate (in replay cache I/O code)"),	/* krb5_err.et:krb5:KRB5_RC_IO_MALLOC */
	N_("Permission denied in replay cache code"),	/* krb5_err.et:krb5:KRB5_RC_IO_PERM */
	N_("I/O error in replay cache i/o code"),	/* krb5_err.et:krb5:KRB5_RC_IO_IO */
	N_("Generic unknown RC/IO error"),	/* krb5_err.et:krb5:KRB5_RC_IO_UNKNOWN */
	N_("Insufficient system space to store replay information"),	/* krb5_err.et:krb5:KRB5_RC_IO_SPACE */
	N_("Can't open/find realm translation file"),	/* krb5_err.et:krb5:KRB5_TRANS_CANTOPEN */
	N_("Improper format of realm translation file"),	/* krb5_err.et:krb5:KRB5_TRANS_BADFORMAT */
	N_("Can't open/find lname translation database"),	/* krb5_err.et:krb5:KRB5_LNAME_CANTOPEN */
	N_("No translation available for requested principal"),	/* krb5_err.et:krb5:KRB5_LNAME_NOTRANS */
	N_("Improper format of translation database entry"),	/* krb5_err.et:krb5:KRB5_LNAME_BADFORMAT */
	N_("Cryptosystem internal error"),	/* krb5_err.et:krb5:KRB5_CRYPTO_INTERNAL */
	N_("Key table name malformed"),	/* krb5_err.et:krb5:KRB5_KT_BADNAME */
	N_("Unknown Key table type"),	/* krb5_err.et:krb5:KRB5_KT_UNKNOWN_TYPE */
	N_("Key table entry not found"),	/* krb5_err.et:krb5:KRB5_KT_NOTFOUND */
	N_("End of key table reached"),	/* krb5_err.et:krb5:KRB5_KT_END */
	N_("Cannot write to specified key table"),	/* krb5_err.et:krb5:KRB5_KT_NOWRITE */
	N_("Error writing to key table"),	/* krb5_err.et:krb5:KRB5_KT_IOERR */
	N_("Cannot find ticket for requested realm"),	/* krb5_err.et:krb5:KRB5_NO_TKT_IN_RLM */
	N_("DES key has bad parity"),	/* krb5_err.et:krb5:KRB5DES_BAD_KEYPAR */
	N_("DES key is a weak key"),	/* krb5_err.et:krb5:KRB5DES_WEAK_KEY */
	N_("Bad encryption type"),	/* krb5_err.et:krb5:KRB5_BAD_ENCTYPE */
	N_("Key size is incompatible with encryption type"),	/* krb5_err.et:krb5:KRB5_BAD_KEYSIZE */
	N_("Message size is incompatible with encryption type"),	/* krb5_err.et:krb5:KRB5_BAD_MSIZE */
	N_("Credentials cache type is already registered."),	/* krb5_err.et:krb5:KRB5_CC_TYPE_EXISTS */
	N_("Key table type is already registered."),	/* krb5_err.et:krb5:KRB5_KT_TYPE_EXISTS */
	N_("Credentials cache I/O operation failed XXX"),	/* krb5_err.et:krb5:KRB5_CC_IO */
	N_("Credentials cache permissions incorrect"),	/* krb5_err.et:krb5:KRB5_FCC_PERM */
	N_("No credentials cache found"),	/* krb5_err.et:krb5:KRB5_FCC_NOFILE */
	N_("Internal credentials cache error"),	/* krb5_err.et:krb5:KRB5_FCC_INTERNAL */
	N_("Error writing to credentials cache"),	/* krb5_err.et:krb5:KRB5_CC_WRITE */
	N_("No more memory to allocate (in credentials cache code)"),	/* krb5_err.et:krb5:KRB5_CC_NOMEM */
	N_("Bad format in credentials cache"),	/* krb5_err.et:krb5:KRB5_CC_FORMAT */
	N_("No credentials found with supported encryption types"),	/* krb5_err.et:krb5:KRB5_CC_NOT_KTYPE */
	N_("Invalid KDC option combination (library internal error)"),	/* krb5_err.et:krb5:KRB5_INVALID_FLAGS */
	N_("Request missing second ticket"),	/* krb5_err.et:krb5:KRB5_NO_2ND_TKT */
	N_("No credentials supplied to library routine"),	/* krb5_err.et:krb5:KRB5_NOCREDS_SUPPLIED */
	N_("Bad sendauth version was sent"),	/* krb5_err.et:krb5:KRB5_SENDAUTH_BADAUTHVERS */
	N_("Bad application version was sent (via sendauth)"),	/* krb5_err.et:krb5:KRB5_SENDAUTH_BADAPPLVERS */
	N_("Bad response (during sendauth exchange)"),	/* krb5_err.et:krb5:KRB5_SENDAUTH_BADRESPONSE */
	N_("Server rejected authentication (during sendauth exchange)"),	/* krb5_err.et:krb5:KRB5_SENDAUTH_REJECTED */
	N_("Unsupported preauthentication type"),	/* krb5_err.et:krb5:KRB5_PREAUTH_BAD_TYPE */
	N_("Required preauthentication key not supplied"),	/* krb5_err.et:krb5:KRB5_PREAUTH_NO_KEY */
	N_("Generic preauthentication failure"),	/* krb5_err.et:krb5:KRB5_PREAUTH_FAILED */
	N_("Unsupported replay cache format version number"),	/* krb5_err.et:krb5:KRB5_RCACHE_BADVNO */
	N_("Unsupported credentials cache format version number"),	/* krb5_err.et:krb5:KRB5_CCACHE_BADVNO */
	N_("Unsupported key table format version number"),	/* krb5_err.et:krb5:KRB5_KEYTAB_BADVNO */
	N_("Program lacks support for address type"),	/* krb5_err.et:krb5:KRB5_PROG_ATYPE_NOSUPP */
	N_("Message replay detection requires rcache parameter"),	/* krb5_err.et:krb5:KRB5_RC_REQUIRED */
	N_("Hostname cannot be canonicalized"),	/* krb5_err.et:krb5:KRB5_ERR_BAD_HOSTNAME */
	N_("Cannot determine realm for host"),	/* krb5_err.et:krb5:KRB5_ERR_HOST_REALM_UNKNOWN */
	N_("Conversion to service principal undefined for name type"),	/* krb5_err.et:krb5:KRB5_SNAME_UNSUPP_NAMETYPE */
	N_("Initial Ticket response appears to be Version 4 error"),	/* krb5_err.et:krb5:KRB5KRB_AP_ERR_V4_REPLY */
	N_("Cannot resolve network address for KDC in requested realm"),	/* krb5_err.et:krb5:KRB5_REALM_CANT_RESOLVE */
	N_("Requesting ticket can't get forwardable tickets"),	/* krb5_err.et:krb5:KRB5_TKT_NOT_FORWARDABLE */
	N_("Bad principal name while trying to forward credentials"),	/* krb5_err.et:krb5:KRB5_FWD_BAD_PRINCIPAL */
	N_("Looping detected inside krb5_get_in_tkt"),	/* krb5_err.et:krb5:KRB5_GET_IN_TKT_LOOP */
	N_("Configuration file does not specify default realm"),	/* krb5_err.et:krb5:KRB5_CONFIG_NODEFREALM */
	N_("Bad SAM flags in obtain_sam_padata"),	/* krb5_err.et:krb5:KRB5_SAM_UNSUPPORTED */
	N_("Invalid encryption type in SAM challenge"),	/* krb5_err.et:krb5:KRB5_SAM_INVALID_ETYPE */
	N_("Missing checksum in SAM challenge"),	/* krb5_err.et:krb5:KRB5_SAM_NO_CHECKSUM */
	N_("Bad checksum in SAM challenge"),	/* krb5_err.et:krb5:KRB5_SAM_BAD_CHECKSUM */
	N_("Keytab name too long"),	/* krb5_err.et:krb5:KRB5_KT_NAME_TOOLONG */
	N_("Key version number for principal in key table is incorrect"),	/* krb5_err.et:krb5:KRB5_KT_KVNONOTFOUND */
	N_("This application has expired"),	/* krb5_err.et:krb5:KRB5_APPL_EXPIRED */
	N_("This Krb5 library has expired"),	/* krb5_err.et:krb5:KRB5_LIB_EXPIRED */
	N_("New password cannot be zero length"),	/* krb5_err.et:krb5:KRB5_CHPW_PWDNULL */
	N_("Password change failed"),	/* krb5_err.et:krb5:KRB5_CHPW_FAIL */
	N_("Bad format in keytab"),	/* krb5_err.et:krb5:KRB5_KT_FORMAT */
	N_("Encryption type not permitted"),	/* krb5_err.et:krb5:KRB5_NOPERM_ETYPE */
	N_("No supported encryption types (config file error?)"),	/* krb5_err.et:krb5:KRB5_CONFIG_ETYPE_NOSUPP */
	N_("Program called an obsolete, deleted function"),	/* krb5_err.et:krb5:KRB5_OBSOLETE_FN */
	N_("unknown getaddrinfo failure"),	/* krb5_err.et:krb5:KRB5_EAI_FAIL */
	N_("no data available for host/domain name"),	/* krb5_err.et:krb5:KRB5_EAI_NODATA */
	N_("host/domain name not found"),	/* krb5_err.et:krb5:KRB5_EAI_NONAME */
	N_("service name unknown"),	/* krb5_err.et:krb5:KRB5_EAI_SERVICE */
	N_("Cannot determine realm for numeric host address"),	/* krb5_err.et:krb5:KRB5_ERR_NUMERIC_REALM */
	N_("Invalid key generation parameters from KDC"),	/* krb5_err.et:krb5:KRB5_ERR_BAD_S2K_PARAMS */
	N_("service not available"),	/* krb5_err.et:krb5:KRB5_ERR_NO_SERVICE */
	N_("Ccache function not supported: read-only ccache type"),	/* krb5_err.et:krb5:KRB5_CC_READONLY */
	N_("Ccache function not supported: not implemented"),	/* krb5_err.et:krb5:KRB5_CC_NOSUPP */
	N_("Invalid format of Kerberos lifetime or clock skew string"),	/* krb5_err.et:krb5:KRB5_DELTAT_BADFORMAT */
	N_("Supplied data not handled by this plugin"),	/* krb5_err.et:krb5:KRB5_PLUGIN_NO_HANDLE */
	N_("Plugin does not support the operaton"),	/* krb5_err.et:krb5:KRB5_PLUGIN_OP_NOTSUPP */
	N_("Kerberos V5 magic number table"),	/* kv5m_err.et:kv5m:KV5M_NONE */
	N_("Bad magic number for krb5_principal structure"),	/* kv5m_err.et:kv5m:KV5M_PRINCIPAL */
	N_("Bad magic number for krb5_data structure"),	/* kv5m_err.et:kv5m:KV5M_DATA */
	N_("Bad magic number for krb5_keyblock structure"),	/* kv5m_err.et:kv5m:KV5M_KEYBLOCK */
	N_("Bad magic number for krb5_checksum structure"),	/* kv5m_err.et:kv5m:KV5M_CHECKSUM */
	N_("Bad magic number for krb5_encrypt_block structure"),	/* kv5m_err.et:kv5m:KV5M_ENCRYPT_BLOCK */
	N_("Bad magic number for krb5_enc_data structure"),	/* kv5m_err.et:kv5m:KV5M_ENC_DATA */
	N_("Bad magic number for krb5_cryptosystem_entry structure"),	/* kv5m_err.et:kv5m:KV5M_CRYPTOSYSTEM_ENTRY */
	N_("Bad magic number for krb5_cs_table_entry structure"),	/* kv5m_err.et:kv5m:KV5M_CS_TABLE_ENTRY */
	N_("Bad magic number for krb5_checksum_entry structure"),	/* kv5m_err.et:kv5m:KV5M_CHECKSUM_ENTRY */
	N_("Bad magic number for krb5_authdata structure"),	/* kv5m_err.et:kv5m:KV5M_AUTHDATA */
	N_("Bad magic number for krb5_transited structure"),	/* kv5m_err.et:kv5m:KV5M_TRANSITED */
	N_("Bad magic number for krb5_enc_tkt_part structure"),	/* kv5m_err.et:kv5m:KV5M_ENC_TKT_PART */
	N_("Bad magic number for krb5_ticket structure"),	/* kv5m_err.et:kv5m:KV5M_TICKET */
	N_("Bad magic number for krb5_authenticator structure"),	/* kv5m_err.et:kv5m:KV5M_AUTHENTICATOR */
	N_("Bad magic number for krb5_tkt_authent structure"),	/* kv5m_err.et:kv5m:KV5M_TKT_AUTHENT */
	N_("Bad magic number for krb5_creds structure"),	/* kv5m_err.et:kv5m:KV5M_CREDS */
	N_("Bad magic number for krb5_last_req_entry structure"),	/* kv5m_err.et:kv5m:KV5M_LAST_REQ_ENTRY */
	N_("Bad magic number for krb5_pa_data structure"),	/* kv5m_err.et:kv5m:KV5M_PA_DATA */
	N_("Bad magic number for krb5_kdc_req structure"),	/* kv5m_err.et:kv5m:KV5M_KDC_REQ */
	N_("Bad magic number for krb5_enc_kdc_rep_part structure"),	/* kv5m_err.et:kv5m:KV5M_ENC_KDC_REP_PART */
	N_("Bad magic number for krb5_kdc_rep structure"),	/* kv5m_err.et:kv5m:KV5M_KDC_REP */
	N_("Bad magic number for krb5_error structure"),	/* kv5m_err.et:kv5m:KV5M_ERROR */
	N_("Bad magic number for krb5_ap_req structure"),	/* kv5m_err.et:kv5m:KV5M_AP_REQ */
	N_("Bad magic number for krb5_ap_rep structure"),	/* kv5m_err.et:kv5m:KV5M_AP_REP */
	N_("Bad magic number for krb5_ap_rep_enc_part structure"),	/* kv5m_err.et:kv5m:KV5M_AP_REP_ENC_PART */
	N_("Bad magic number for krb5_response structure"),	/* kv5m_err.et:kv5m:KV5M_RESPONSE */
	N_("Bad magic number for krb5_safe structure"),	/* kv5m_err.et:kv5m:KV5M_SAFE */
	N_("Bad magic number for krb5_priv structure"),	/* kv5m_err.et:kv5m:KV5M_PRIV */
	N_("Bad magic number for krb5_priv_enc_part structure"),	/* kv5m_err.et:kv5m:KV5M_PRIV_ENC_PART */
	N_("Bad magic number for krb5_cred structure"),	/* kv5m_err.et:kv5m:KV5M_CRED */
	N_("Bad magic number for krb5_cred_info structure"),	/* kv5m_err.et:kv5m:KV5M_CRED_INFO */
	N_("Bad magic number for krb5_cred_enc_part structure"),	/* kv5m_err.et:kv5m:KV5M_CRED_ENC_PART */
	N_("Bad magic number for krb5_pwd_data structure"),	/* kv5m_err.et:kv5m:KV5M_PWD_DATA */
	N_("Bad magic number for krb5_address structure"),	/* kv5m_err.et:kv5m:KV5M_ADDRESS */
	N_("Bad magic number for krb5_keytab_entry structure"),	/* kv5m_err.et:kv5m:KV5M_KEYTAB_ENTRY */
	N_("Bad magic number for krb5_context structure"),	/* kv5m_err.et:kv5m:KV5M_CONTEXT */
	N_("Bad magic number for krb5_os_context structure"),	/* kv5m_err.et:kv5m:KV5M_OS_CONTEXT */
	N_("Bad magic number for krb5_alt_method structure"),	/* kv5m_err.et:kv5m:KV5M_ALT_METHOD */
	N_("Bad magic number for krb5_etype_info_entry structure"),	/* kv5m_err.et:kv5m:KV5M_ETYPE_INFO_ENTRY */
	N_("Bad magic number for krb5_db_context structure"),	/* kv5m_err.et:kv5m:KV5M_DB_CONTEXT */
	N_("Bad magic number for krb5_auth_context structure"),	/* kv5m_err.et:kv5m:KV5M_AUTH_CONTEXT */
	N_("Bad magic number for krb5_keytab structure"),	/* kv5m_err.et:kv5m:KV5M_KEYTAB */
	N_("Bad magic number for krb5_rcache structure"),	/* kv5m_err.et:kv5m:KV5M_RCACHE */
	N_("Bad magic number for krb5_ccache structure"),	/* kv5m_err.et:kv5m:KV5M_CCACHE */
	N_("Bad magic number for krb5_preauth_ops"),	/* kv5m_err.et:kv5m:KV5M_PREAUTH_OPS */
	N_("Bad magic number for krb5_sam_challenge"),	/* kv5m_err.et:kv5m:KV5M_SAM_CHALLENGE */
	N_("Bad magic number for krb5_sam_challenge_2"),	/* kv5m_err.et:kv5m:KV5M_SAM_CHALLENGE_2 */
	N_("Bad magic number for krb5_sam_key"),	/* kv5m_err.et:kv5m:KV5M_SAM_KEY */
	N_("Bad magic number for krb5_enc_sam_response_enc"),	/* kv5m_err.et:kv5m:KV5M_ENC_SAM_RESPONSE_ENC */
	N_("Bad magic number for krb5_enc_sam_response_enc"),	/* kv5m_err.et:kv5m:KV5M_ENC_SAM_RESPONSE_ENC_2 */
	N_("Bad magic number for krb5_sam_response"),	/* kv5m_err.et:kv5m:KV5M_SAM_RESPONSE */
	N_("Bad magic number for krb5_sam_response 2"),	/* kv5m_err.et:kv5m:KV5M_SAM_RESPONSE_2 */
	N_("Bad magic number for krb5_predicted_sam_response"),	/* kv5m_err.et:kv5m:KV5M_PREDICTED_SAM_RESPONSE */
	N_("Bad magic number for passwd_phrase_element"),	/* kv5m_err.et:kv5m:KV5M_PASSWD_PHRASE_ELEMENT */
	N_("Bad magic number for GSSAPI OID"),	/* kv5m_err.et:kv5m:KV5M_GSS_OID */
	N_("Bad magic number for GSSAPI QUEUE"),	/* kv5m_err.et:kv5m:KV5M_GSS_QUEUE */
	NULL
};