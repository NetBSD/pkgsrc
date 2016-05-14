$NetBSD: patch-lib_vtls_openssl.c,v 1.1 2016/05/14 18:36:02 sevan Exp $

Add support for building with LibreSSL/BoringSSL
https://github.com/curl/curl/commit/240cd84b494e0ffee8ad261c43b927d246cf6be1

--- lib/vtls/openssl.c.orig	Sat May 14 15:53:20 2016
+++ lib/vtls/openssl.c
@@ -95,7 +95,9 @@
 
 #if (OPENSSL_VERSION_NUMBER >= 0x10000000L)
 #define HAVE_ERR_REMOVE_THREAD_STATE 1
-#if (OPENSSL_VERSION_NUMBER >= 0x10100004L)
+#if (OPENSSL_VERSION_NUMBER >= 0x10100004L) && \
+  !defined(LIBRESSL_VERSION_NUMBER) && \
+  !defined(OPENSSL_IS_BORINGSSL)
 /* OpenSSL 1.1.0-pre4 removed the argument! */
 #define HAVE_ERR_REMOVE_THREAD_STATE_NOARG 1
 #endif
