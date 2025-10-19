$NetBSD: patch-media_ffvpx_libavutil_arm_bswap.h,v 1.1 2025/10/19 11:56:56 leot Exp $

Fix NetBSD aarch64 build.

--- media/ffvpx/libavutil/arm/bswap.h.orig	2025-02-21 13:24:25.000000000 +0000
+++ media/ffvpx/libavutil/arm/bswap.h
@@ -23,6 +23,8 @@
 #include "config.h"
 #include "libavutil/attributes.h"
 
+#ifndef __aarch64__
+
 #ifdef __ARMCC_VERSION
 
 #if HAVE_ARMV6
@@ -47,4 +49,6 @@ static av_always_inline av_const unsigne
 #endif
 #endif /* __ARMCC_VERSION */
 
+#endif /* __aarch64__ */
+
 #endif /* AVUTIL_ARM_BSWAP_H */
