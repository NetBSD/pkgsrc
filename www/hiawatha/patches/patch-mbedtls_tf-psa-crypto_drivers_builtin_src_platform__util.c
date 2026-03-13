$NetBSD: patch-mbedtls_tf-psa-crypto_drivers_builtin_src_platform__util.c,v 1.2 2026/03/13 21:09:18 hauke Exp $

    Fix build on NetBSD (from security/mbedtls4)

--- mbedtls/tf-psa-crypto/drivers/builtin/src/platform_util.c.orig	2026-03-12 19:02:22.000000000 +0000
+++ mbedtls/tf-psa-crypto/drivers/builtin/src/platform_util.c
@@ -11,7 +11,7 @@
  * mbedtls_config.h, which pulls in glibc's features.h. Harmless on other platforms
  * except OpenBSD, where it stops us accessing explicit_bzero.
  */
-#if !defined(_POSIX_C_SOURCE) && !defined(__OpenBSD__)
+#if !defined(_POSIX_C_SOURCE) && !defined(__OpenBSD__) && !defined(__NetBSD__)
 #define _POSIX_C_SOURCE 200112L
 #endif
 
