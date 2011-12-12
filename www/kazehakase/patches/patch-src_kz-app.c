$NetBSD: patch-src_kz-app.c,v 1.1 2011/12/12 19:10:37 joerg Exp $

--- src/kz-app.c.orig	2011-12-12 17:41:34.000000000 +0000
+++ src/kz-app.c
@@ -494,7 +494,9 @@ kz_app_init (KzApp *app)
 
 #ifdef USE_SSL
         /* initialize gnutls. this function should be called once. */
+#if GNUTLS_VERSION_NUMBER <= 0x020b00
 	gcry_control(GCRYCTL_SET_THREAD_CBS, &gcry_threads_pthread);
+#endif
 	gnutls_global_init();
 #endif
 
