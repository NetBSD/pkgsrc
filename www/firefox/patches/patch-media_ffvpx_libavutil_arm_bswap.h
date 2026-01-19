$NetBSD: patch-media_ffvpx_libavutil_arm_bswap.h,v 1.4 2026/01/19 12:06:04 ryoon Exp $

avutil/arm/bswap.h is preferred over the system's <arm/bswap.h> due to
Firefox's include path order. This breaks <stdlib.h> and others, so
make sure to pull in the system header when this happens.

--- media/ffvpx/libavutil/arm/bswap.h.orig	2025-12-31 13:17:28.000000000 +0000
+++ media/ffvpx/libavutil/arm/bswap.h
@@ -16,6 +16,10 @@
  * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
  */
 
+#if defined(__NetBSD__)
+#include "/usr/include/arm/bswap.h"
+#endif
+
 #ifndef AVUTIL_ARM_BSWAP_H
 #define AVUTIL_ARM_BSWAP_H
 
@@ -23,6 +27,8 @@
 #include "config.h"
 #include "libavutil/attributes.h"
 
+#ifndef __aarch64__
+
 #ifdef __ARMCC_VERSION
 
 #if HAVE_ARMV6
@@ -46,5 +52,7 @@ static av_always_inline av_const unsigned av_bswap16(u
 }
 #endif
 #endif /* __ARMCC_VERSION */
+
+#endif /* __aarch64__ */
 
 #endif /* AVUTIL_ARM_BSWAP_H */
