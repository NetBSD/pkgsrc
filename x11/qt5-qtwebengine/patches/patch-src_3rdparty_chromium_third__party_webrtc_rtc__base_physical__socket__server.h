$NetBSD: patch-src_3rdparty_chromium_third__party_webrtc_rtc__base_physical__socket__server.h,v 1.1 2021/08/03 21:04:36 markd Exp $

--- src/3rdparty/chromium/third_party/webrtc/rtc_base/physical_socket_server.h.orig	2020-07-15 19:01:42.000000000 +0000
+++ src/3rdparty/chromium/third_party/webrtc/rtc_base/physical_socket_server.h
@@ -11,7 +11,7 @@
 #ifndef RTC_BASE_PHYSICAL_SOCKET_SERVER_H_
 #define RTC_BASE_PHYSICAL_SOCKET_SERVER_H_
 
-#if defined(WEBRTC_POSIX) && defined(WEBRTC_LINUX)
+#if defined(WEBRTC_POSIX) && defined(WEBRTC_LINUX) && !defined(WEBRTC_BSD)
 #include <sys/epoll.h>
 #define WEBRTC_USE_EPOLL 1
 #endif
