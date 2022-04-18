$NetBSD: patch-src_3rdparty_chromium_third__party_webrtc_rtc__base_network.h,v 1.2 2022/04/18 11:18:19 adam Exp $

--- src/3rdparty/chromium/third_party/webrtc/rtc_base/network.h.orig	2021-02-19 16:41:59.000000000 +0000
+++ src/3rdparty/chromium/third_party/webrtc/rtc_base/network.h
@@ -30,6 +30,10 @@
 #include "rtc_base/thread_annotations.h"
 
 #if defined(WEBRTC_POSIX)
+#include <sys/types.h>
+#endif
+
+#if defined(WEBRTC_POSIX)
 struct ifaddrs;
 #endif  // defined(WEBRTC_POSIX)
 
