$NetBSD: patch-mbedtls_tf-psa-crypto_drivers_builtin_src_platform__util.c,v 1.1 2026/03/13 21:02:50 hauke Exp $

Make devmajor_t and friends available on NetBSD for KERN_ARND support

--- mbedtls/tf-psa-crypto/drivers/builtin/src/platform_util.c.orig	2026-03-12 19:02:22.000000000 +0000
+++ mbedtls/tf-psa-crypto/drivers/builtin/src/platform_util.c
@@ -20,6 +20,10 @@
 #define _GNU_SOURCE
 #endif
 
+#if defined(__NetBSD__)
+#define _NETBSD_SOURCE
+#endif
+
 #include "tf_psa_crypto_common.h"
 
 #include "mbedtls/platform_util.h"
