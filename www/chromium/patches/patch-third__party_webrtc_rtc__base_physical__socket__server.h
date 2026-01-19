$NetBSD: patch-third__party_webrtc_rtc__base_physical__socket__server.h,v 1.14 2026/01/19 16:14:21 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/webrtc/rtc_base/physical_socket_server.h.orig	2026-01-07 00:50:30.000000000 +0000
+++ third_party/webrtc/rtc_base/physical_socket_server.h
@@ -22,7 +22,7 @@
 #include "rtc_base/socket_address.h"
 
 #if defined(WEBRTC_POSIX)
-#if defined(WEBRTC_LINUX)
+#if defined(WEBRTC_LINUX) && !defined(WEBRTC_BSD)
 // On Linux, use epoll.
 #include <sys/epoll.h>
 
