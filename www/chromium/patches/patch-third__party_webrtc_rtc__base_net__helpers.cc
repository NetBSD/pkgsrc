$NetBSD: patch-third__party_webrtc_rtc__base_net__helpers.cc,v 1.2 2025/07/25 16:17:22 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/webrtc/rtc_base/net_helpers.cc.orig	2025-07-21 19:32:31.000000000 +0000
+++ third_party/webrtc/rtc_base/net_helpers.cc
@@ -21,6 +21,7 @@
 #endif
 #if defined(WEBRTC_POSIX) && !defined(__native_client__)
 #include <arpa/inet.h>
+#include <sys/socket.h>
 #endif  // defined(WEBRTC_POSIX) && !defined(__native_client__)
 
 namespace webrtc {
