$NetBSD: patch-third__party_webrtc_rtc__base_physical__socket__server.h,v 1.16 2026/03/14 12:40:43 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/webrtc/rtc_base/physical_socket_server.h.orig	2026-03-11 22:12:25.000000000 +0000
+++ third_party/webrtc/rtc_base/physical_socket_server.h
@@ -22,7 +22,7 @@
 #include "rtc_base/socket_address.h"
 
 #if defined(WEBRTC_POSIX)
-#if defined(WEBRTC_LINUX)
+#if defined(WEBRTC_LINUX) && !defined(WEBRTC_BSD)
 // On Linux, use epoll.
 #include <sys/epoll.h>
 
