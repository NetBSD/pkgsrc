$NetBSD: patch-lib_neon_ne__privssl.h,v 1.1 2020/04/25 13:47:31 nia Exp $

Fix build with newer gnutls.

--- lib/neon/ne_privssl.h.orig	2009-09-02 14:04:43.000000000 +0000
+++ lib/neon/ne_privssl.h
@@ -59,7 +59,7 @@ ne__ssl_clicert_exkey_import(const unsig
 #include <gnutls/gnutls.h>
 
 struct ne_ssl_context_s {
-    gnutls_certificate_credentials cred;
+    gnutls_certificate_credentials_t cred;
     int verify; /* non-zero if client cert verification required */
 
     const char *hostname; /* for SNI */
@@ -67,10 +67,10 @@ struct ne_ssl_context_s {
     /* Session cache. */
     union ne_ssl_scache {
         struct {
-            gnutls_datum key, data;
+            gnutls_datum_t key, data;
         } server;
 #if defined(HAVE_GNUTLS_SESSION_GET_DATA2)
-        gnutls_datum client;
+        gnutls_datum_t client;
 #else
         struct {
             char *data;
@@ -85,7 +85,7 @@ struct ne_ssl_context_s {
 #endif
 };
 
-typedef gnutls_session ne_ssl_socket;
+typedef gnutls_session_t ne_ssl_socket;
 
 NE_PRIVATE ne_ssl_client_cert *
 ne__ssl_clicert_exkey_import(const unsigned char *der, size_t der_len);
