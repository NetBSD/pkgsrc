$NetBSD: patch-modules_ssl_ssl__private.h,v 1.1 2012/07/05 12:50:44 ryoon Exp $

Exclude OpenSSL shipped with NetBSD current and 6.0.
It is pre-beta snapshot of 1.0.1.

--- modules/ssl/ssl_private.h.orig	2012-04-03 12:37:57.000000000 +0000
+++ modules/ssl/ssl_private.h
@@ -83,7 +83,7 @@
 
 /* OpenSSL headers */
 #include <openssl/opensslv.h>
-#if (OPENSSL_VERSION_NUMBER >= 0x10001000)
+#if (OPENSSL_VERSION_NUMBER >= 0x10001001)
 /* must be defined before including ssl.h */
 #define OPENSSL_NO_SSL_INTERN
 #endif
