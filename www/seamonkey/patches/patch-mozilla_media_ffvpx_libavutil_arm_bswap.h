$NetBSD: patch-mozilla_media_ffvpx_libavutil_arm_bswap.h,v 1.1 2020/06/26 11:40:28 nia Exp $

Fix NetBSD aarch64 build.

--- mozilla/media/ffvpx/libavutil/arm/bswap.h.orig	2020-02-17 23:37:58.000000000 +0000
+++ mozilla/media/ffvpx/libavutil/arm/bswap.h
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
