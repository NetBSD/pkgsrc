$NetBSD: patch-http.c,v 1.1 2019/09/09 09:08:08 nia Exp $

[PATCH] Support for Openssl 1.1
https://github.com/graygnuorg/pound/commit/a2c9dde4d055ea8942afb150b7fc3a807d4e5d60.patch

--- http.c.orig	2018-05-11 10:16:05.000000000 +0000
+++ http.c
@@ -527,12 +527,22 @@ log_bytes(char *res, const LONG cnt)
 
 /* Cleanup code. This should really be in the pthread_cleanup_push, except for bugs in some implementations */
 
+#if OPENSSL_VERSION_NUMBER >= 0x10100000L
+# define clear_error()
+#elif OPENSSL_VERSION_NUMBER >= 0x10000000L
+# define clear_error() \
+	if(ssl != NULL) { ERR_clear_error(); ERR_remove_thread_state(NULL); }
+#else
+# define clear_error() \
+	if(ssl != NULL) { ERR_clear_error(); ERR_remove_state(0); }
+#endif
+
 #define clean_all() {   \
     if(ssl != NULL) { BIO_ssl_shutdown(cl); } \
     if(be != NULL) { BIO_flush(be); BIO_reset(be); BIO_free_all(be); be = NULL; } \
     if(cl != NULL) { BIO_flush(cl); BIO_reset(cl); BIO_free_all(cl); cl = NULL; } \
     if(x509 != NULL) { X509_free(x509); x509 = NULL; } \
-    if(ssl != NULL) { ERR_clear_error(); ERR_remove_state(0); } \
+    clear_error(); \
 }
 
 /*
