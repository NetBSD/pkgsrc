$NetBSD: patch-third__party_webrtc_rtc__base_byte__order.h,v 1.20 2026/06/01 10:09:22 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/webrtc/rtc_base/byte_order.h.orig	2026-05-26 20:39:02.000000000 +0000
+++ third_party/webrtc/rtc_base/byte_order.h
@@ -84,6 +84,8 @@
 #error WEBRTC_ARCH_BIG_ENDIAN or WEBRTC_ARCH_LITTLE_ENDIAN must be defined.
 #endif  // defined(WEBRTC_ARCH_LITTLE_ENDIAN)
 
+#elif defined(WEBRTC_BSD)
+#include <sys/endian.h>
 #elif defined(WEBRTC_POSIX)
 #include <endian.h>
 #else
