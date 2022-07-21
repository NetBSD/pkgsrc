$NetBSD: patch-media_ffvpx_libavutil_arm_bswap.h,v 1.1 2022/07/21 23:56:39 nia Exp $

Fix NetBSD aarch64 build.

--- media/ffvpx/libavutil/arm/bswap.h.orig	2019-10-30 17:35:56.000000000 +0000
+++ media/ffvpx/libavutil/arm/bswap.h
@@ -23,6 +23,8 @@
 #include "config.h"
 #include "libavutil/attributes.h"
 
+#ifndef __aarch64__
+
 #ifdef __ARMCC_VERSION
 
 #if HAVE_ARMV6
@@ -64,4 +66,6 @@ static av_always_inline av_const uint32_
 
 #endif /* __ARMCC_VERSION */
 
+#endif /* __aarch64__ */
+
 #endif /* AVUTIL_ARM_BSWAP_H */
