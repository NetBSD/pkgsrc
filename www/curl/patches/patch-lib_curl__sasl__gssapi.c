$NetBSD: patch-lib_curl__sasl__gssapi.c,v 1.1 2015/01/08 19:23:53 wiz Exp $

Fix build on NetBSD with gssapi.

--- lib/curl_sasl_gssapi.c.orig	2015-01-07 21:53:57.000000000 +0000
+++ lib/curl_sasl_gssapi.c
@@ -126,7 +126,7 @@ CURLcode Curl_sasl_create_gssapi_user_me
 
     /* Import the SPN */
     gss_major_status = gss_import_name(&gss_minor_status, &spn_token,
-                                       gss_nt_service_name, &krb5->spn);
+                                       GSS_C_NT_HOSTBASED_SERVICE, &krb5->spn);
     if(GSS_ERROR(gss_major_status)) {
       Curl_gss_log_error(data, gss_minor_status, "gss_import_name() failed: ");
 
