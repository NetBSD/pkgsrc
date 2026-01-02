$NetBSD: patch-platform_media_ffvpx_libavutil_arm_bswap.h,v 1.1 2026/01/02 20:42:17 tnn Exp $

avutil/arm/bswap.h is preferred over the system's <arm/bswap.h> due to
Firefox's include path order. This breaks <stdlib.h> and others, so
make sure to pull in the system header when this happens.

--- platform/media/ffvpx/libavutil/arm/bswap.h.orig	2026-01-02 19:16:36.842902642 +0000
+++ platform/media/ffvpx/libavutil/arm/bswap.h
@@ -19,10 +19,16 @@
 #ifndef AVUTIL_ARM_BSWAP_H
 #define AVUTIL_ARM_BSWAP_H
 
+#if defined(__NetBSD__)
+#include "/usr/include/arm/bswap.h"
+#endif
+
 #include <stdint.h>
 #include "config.h"
 #include "libavutil/attributes.h"
 
+#ifndef __aarch64__
+
 #ifdef __ARMCC_VERSION
 
 #if HAVE_ARMV6
@@ -67,4 +73,6 @@ static av_always_inline av_const uint32_
 
 #endif /* __ARMCC_VERSION */
 
+#endif /* __aarch64__ */
+
 #endif /* AVUTIL_ARM_BSWAP_H */
