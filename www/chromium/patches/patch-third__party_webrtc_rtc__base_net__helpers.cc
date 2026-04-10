$NetBSD: patch-third__party_webrtc_rtc__base_net__helpers.cc,v 1.15 2026/04/10 17:32:01 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/webrtc/rtc_base/net_helpers.cc.orig	2026-04-06 16:25:54.000000000 +0000
+++ third_party/webrtc/rtc_base/net_helpers.cc
@@ -20,6 +20,7 @@
 #endif
 #if defined(WEBRTC_POSIX)
 #include <arpa/inet.h>
+#include <sys/socket.h>
 #endif  // defined(WEBRTC_POSIX)
 
 namespace webrtc {
