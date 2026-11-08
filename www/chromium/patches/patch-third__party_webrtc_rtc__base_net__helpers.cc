$NetBSD: patch-third__party_webrtc_rtc__base_net__helpers.cc,v 1.30 2026/11/08 15:39:12 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/webrtc/rtc_base/net_helpers.cc.orig	2026-11-02 23:22:33.000000000 +0000
+++ third_party/webrtc/rtc_base/net_helpers.cc
@@ -20,6 +20,7 @@
 #endif
 #if defined(WEBRTC_POSIX)
 #include <arpa/inet.h>
+#include <sys/socket.h>
 #endif  // defined(WEBRTC_POSIX)
 
 namespace webrtc {
