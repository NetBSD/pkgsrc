$NetBSD: patch-third__party_webrtc_rtc__base_physical__socket__server.h,v 1.3 2025/07/07 09:23:38 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/webrtc/rtc_base/physical_socket_server.h.orig	2025-06-30 06:54:11.000000000 +0000
+++ third_party/webrtc/rtc_base/physical_socket_server.h
@@ -21,7 +21,7 @@
 #include "rtc_base/third_party/sigslot/sigslot.h"
 
 #if defined(WEBRTC_POSIX)
-#if defined(WEBRTC_LINUX)
+#if defined(WEBRTC_LINUX) && !defined(WEBRTC_BSD)
 // On Linux, use epoll.
 #include <sys/epoll.h>
 
