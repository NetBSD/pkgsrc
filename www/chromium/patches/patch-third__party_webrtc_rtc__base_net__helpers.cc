$NetBSD: patch-third__party_webrtc_rtc__base_net__helpers.cc,v 1.31 2026/11/19 19:46:09 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/webrtc/rtc_base/net_helpers.cc.orig	2026-11-11 21:01:38.000000000 +0000
+++ third_party/webrtc/rtc_base/net_helpers.cc
@@ -20,6 +20,7 @@
 #endif
 #if defined(WEBRTC_POSIX)
 #include <arpa/inet.h>
+#include <sys/socket.h>
 #endif  // defined(WEBRTC_POSIX)
 
 namespace webrtc {
