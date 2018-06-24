$NetBSD: patch-Library_src_SSL_HTSSL.c,v 1.1 2018/06/24 16:54:59 adam Exp $

Fix for OpenSSL 1.1.x.

--- Library/src/SSL/HTSSL.c.orig	2018-06-24 13:38:32.023842509 +0000
+++ Library/src/SSL/HTSSL.c
@@ -98,6 +98,7 @@ PRIVATE void apps_ssl_info_callback (SSL
 PRIVATE int verify_callback (int ok, X509_STORE_CTX * ctx)
 {
     char buf[256];
+    int ctx_error;
     X509 * err_cert = X509_STORE_CTX_get_current_cert(ctx);
     int err = X509_STORE_CTX_get_error(ctx);
     int depth = X509_STORE_CTX_get_error_depth(ctx);
@@ -115,24 +116,24 @@ PRIVATE int verify_callback (int ok, X50
 	    verify_error=X509_V_ERR_CERT_CHAIN_TOO_LONG;
 	}
     }
-    switch (ctx->error) {
+    switch (ctx_error = X509_STORE_CTX_get_error(ctx)) {
 
     case X509_V_ERR_UNABLE_TO_GET_ISSUER_CERT:
-	X509_NAME_oneline(X509_get_issuer_name(ctx->current_cert), buf, 256);
+	X509_NAME_oneline(X509_get_issuer_name(X509_STORE_CTX_get0_cert(ctx)), buf, 256);
 	HTTRACE(PROT_TRACE, "issuer= %s\n" _ buf);
 	break;
 
     case X509_V_ERR_CERT_NOT_YET_VALID:
     case X509_V_ERR_ERROR_IN_CERT_NOT_BEFORE_FIELD:
 	HTTRACE(PROT_TRACE, "notBefore=");
-//	ASN1_TIME_print(bio_err,X509_get_notBefore(ctx->current_cert));
+//	ASN1_TIME_print(bio_err,X509_get_notBefore(X509_STORE_CTX_get0_cert(ctx)));
 	HTTRACE(PROT_TRACE, "\n");
 	break;
 
     case X509_V_ERR_CERT_HAS_EXPIRED:
     case X509_V_ERR_ERROR_IN_CERT_NOT_AFTER_FIELD:
 	HTTRACE(PROT_TRACE, "notAfter=");
-//	ASN1_TIME_print(bio_err,X509_get_notAfter(ctx->current_cert));
+//	ASN1_TIME_print(bio_err,X509_get_notAfter(X509_STORE_CTX_get0_cert(ctx)));
 	HTTRACE(PROT_TRACE, "\n");
 	break;
     }
@@ -214,12 +215,6 @@ PUBLIC BOOL HTSSL_init (void)
 
 	/* select the protocol method */
 	switch (ssl_prot_method) {
-	case HTSSL_V2:
-	  meth = SSLv2_client_method();
-	  break;
-	case HTSSL_V3:
-	  meth = SSLv3_client_method();
-	  break;
 	case HTSSL_V23:
 	  meth = SSLv23_client_method();
 	  break;
