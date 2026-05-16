$NetBSD: patch-src_mod__auth__gssapi.c,v 1.1 2026/05/16 03:47:29 riastradh Exp $

1. Provide definitions of older GSSAPI OIDs not in Heimdal.

2. Conditionalize use of gss_set_neg_mechs and gss_str_to_oid APIs.

--- src/mod_auth_gssapi.c.orig	2022-08-29 10:27:33.722115054 +0000
+++ src/mod_auth_gssapi.c
@@ -440,6 +440,21 @@ const char *mag_str_auth_type(int auth_t
     return auth_types[auth_type];
 }
 
+#ifndef HAVE_GSS_MECH_KRB5_OLD
+static const gss_const_OID gss_mech_krb5_old =
+    &(const gss_OID_desc){5, "\053\005\001\005\002"};
+#endif
+
+#ifndef HAVE_GSS_MECH_KRB5_WRONG
+static const gss_const_OID gss_mech_krb5_wrong =
+    &(const gss_OID_desc){9, "\052\206\110\202\367\022\001\002\002"};
+#endif
+
+#ifndef HAVE_GSS_MECH_IAKERB
+static const gss_const_OID gss_mech_iakerb =
+    &(const gss_OID_desc){6, "\053\006\001\005\002\005"};
+#endif
+
 gss_OID_set mag_filter_unwanted_mechs(gss_OID_set src)
 {
     gss_const_OID unwanted_mechs[] = {
@@ -1228,7 +1243,11 @@ static int mag_auth(request_rec *req)
 
     if (auth_type == AUTH_TYPE_NEGOTIATE &&
         cfg->allowed_mechs != GSS_C_NO_OID_SET) {
+#ifdef HAVE_GSS_SET_NEG_MECHS
         maj = gss_set_neg_mechs(&min, acquired_cred, cfg->allowed_mechs);
+#else
+        maj = GSS_S_UNAVAILABLE;
+#endif
         if (GSS_ERROR(maj)) {
             mag_post_error(req, cfg, MAG_GSS_ERR, maj, min,
                            "In Negotiate Auth: gss_set_neg_mechs() failed");
@@ -1784,7 +1803,11 @@ static bool mag_list_of_mechs(cmd_parms 
     } else {
         buf.value = discard_const(w);
         buf.length = strlen(w);
+#ifdef HAVE_GSS_STR_TO_OID
         maj = gss_str_to_oid(&min, &buf, &oid);
+#else
+        maj = GSS_S_UNAVAILABLE;
+#endif
         if (maj != GSS_S_COMPLETE) {
             ap_log_error(APLOG_MARK, APLOG_ERR, 0, parms->server,
                          "Unrecognized GSSAPI Mechanism: [%s]", w);
