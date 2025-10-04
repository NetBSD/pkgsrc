$NetBSD: patch-Library_src_SSL_HTSSL.c,v 1.3 2025/10/04 13:37:08 tnn Exp $

Fix for OpenSSL 1.1.x.

--- Library/src/SSL/HTSSL.c.orig	2017-06-24 05:51:38.000000000 +0000
+++ Library/src/SSL/HTSSL.c
@@ -5,3 +5,3 @@
 **	
-**	Copyright © 1995-1998 World Wide Web Consortium, (Massachusetts
+**	Copyright Â© 1995-1998 World Wide Web Consortium, (Massachusetts
 **	Institute of Technology, Institut National de Recherche en
@@ -67,3 +67,3 @@ PRIVATE char *key_file = NULL;
 */
-PRIVATE void apps_ssl_info_callback (SSL * s, int where, int ret)
+PRIVATE void apps_ssl_info_callback (const SSL * s, int where, int ret)
 {
@@ -100,2 +100,3 @@ PRIVATE int verify_callback (int ok, X50
     char buf[256];
+    int ctx_error;
     X509 * err_cert = X509_STORE_CTX_get_current_cert(ctx);
@@ -117,6 +118,10 @@ PRIVATE int verify_callback (int ok, X50
     }
-    switch (ctx->error) {
+    switch (ctx_error = X509_STORE_CTX_get_error(ctx)) {
 
     case X509_V_ERR_UNABLE_TO_GET_ISSUER_CERT:
+#if OPENSSL_VERSION_NUMBER >= 0x10100000
+	X509_NAME_oneline(X509_get_issuer_name(X509_STORE_CTX_get0_cert(ctx)), buf, 256);
+#else
 	X509_NAME_oneline(X509_get_issuer_name(ctx->current_cert), buf, 256);
+#endif
 	HTTRACE(PROT_TRACE, "issuer= %s\n" _ buf);
@@ -127,3 +132,3 @@ PRIVATE int verify_callback (int ok, X50
 	HTTRACE(PROT_TRACE, "notBefore=");
-//	ASN1_TIME_print(bio_err,X509_get_notBefore(ctx->current_cert));
+//	ASN1_TIME_print(bio_err,X509_get_notBefore(X509_STORE_CTX_get0_cert(ctx)));
 	HTTRACE(PROT_TRACE, "\n");
@@ -134,3 +139,3 @@ PRIVATE int verify_callback (int ok, X50
 	HTTRACE(PROT_TRACE, "notAfter=");
-//	ASN1_TIME_print(bio_err,X509_get_notAfter(ctx->current_cert));
+//	ASN1_TIME_print(bio_err,X509_get_notAfter(X509_STORE_CTX_get0_cert(ctx)));
 	HTTRACE(PROT_TRACE, "\n");
@@ -209,3 +214,3 @@ PUBLIC BOOL HTSSL_init (void)
     if (!app_ctx) {
-	SSL_METHOD * meth = NULL;
+	const SSL_METHOD * meth = NULL;
         SSLeay_add_ssl_algorithms();
@@ -216,8 +221,2 @@ PUBLIC BOOL HTSSL_init (void)
 	switch (ssl_prot_method) {
-	case HTSSL_V2:
-	  meth = SSLv2_client_method();
-	  break;
-	case HTSSL_V3:
-	  meth = SSLv3_client_method();
-	  break;
 	case HTSSL_V23:
