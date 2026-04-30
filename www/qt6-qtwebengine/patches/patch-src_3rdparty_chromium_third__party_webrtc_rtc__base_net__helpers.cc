$NetBSD: patch-src_3rdparty_chromium_third__party_webrtc_rtc__base_net__helpers.cc,v 1.1 2026/04/30 06:39:44 adam Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/third_party/webrtc/rtc_base/net_helpers.cc.orig	2026-04-22 10:46:56.282929550 +0000
+++ src/3rdparty/chromium/third_party/webrtc/rtc_base/net_helpers.cc
@@ -20,6 +20,7 @@
 #endif
 #if defined(WEBRTC_POSIX)
 #include <arpa/inet.h>
+#include <sys/socket.h>
 #endif  // defined(WEBRTC_POSIX)
 
 namespace webrtc {
