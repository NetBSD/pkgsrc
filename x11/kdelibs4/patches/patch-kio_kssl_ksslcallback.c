$NetBSD: patch-kio_kssl_ksslcallback.c,v 1.1 2018/01/17 18:53:25 markd Exp $

Support openssl-1.1 

--- kio/kssl/ksslcallback.c.orig	2016-12-08 18:44:10.000000000 +0000
+++ kio/kssl/ksslcallback.c
@@ -28,7 +28,7 @@ bool KSSL_X509CallBack_ca_found;
 extern "C" {
 static int X509Callback(int ok, X509_STORE_CTX *ctx) {
  
-  kDebug(7029) << "X509Callback: ok = " << ok << " error = " << ctx->error << " depth = " << ctx->error_depth;
+  //kDebug(7029) << "X509Callback: ok = " << ok << " error = " << ctx->error << " depth = " << ctx->error_depth;
   // Here is how this works.  We put "ok = 1;" in any case that we
   // don't consider to be an error.  In that case, it will return OK
   // for the certificate check as long as there are no other critical
@@ -39,14 +39,18 @@ static int X509Callback(int ok, X509_STO
 
   if (KSSL_X509CallBack_ca)
   {
+#if OPENSSL_VERSION_NUMBER < 0x10100000L
      if (KOSSL::self()->X509_cmp(ctx->current_cert, KSSL_X509CallBack_ca) != 0)
+#else
+     if (KOSSL::self()->X509_cmp(X509_STORE_CTX_get0_cert(ctx), KSSL_X509CallBack_ca) != 0)
+#endif
         return 1; // Ignore errors for this certificate
 
      KSSL_X509CallBack_ca_found = true;
   }
  
   if (!ok) {
-    switch (ctx->error) {
+    switch (X509_STORE_CTX_get_error(ctx)) {
       case X509_V_ERR_UNABLE_TO_GET_ISSUER_CERT:
       case X509_V_ERR_UNABLE_TO_GET_CRL:
       case X509_V_ERR_UNABLE_TO_DECRYPT_CERT_SIGNATURE:
