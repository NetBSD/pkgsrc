$NetBSD: patch-src_3rdparty_chromium_net_socket_udp__socket__posix.h,v 1.2 2022/04/18 11:18:19 adam Exp $

--- src/3rdparty/chromium/net/socket/udp_socket_posix.h.orig	2021-02-19 16:41:59.000000000 +0000
+++ src/3rdparty/chromium/net/socket/udp_socket_posix.h
@@ -35,7 +35,7 @@
 
 #if defined(__ANDROID__) && defined(__aarch64__)
 #define HAVE_SENDMMSG 1
-#elif defined(OS_LINUX) || defined(OS_CHROMEOS)
+#elif defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 #define HAVE_SENDMMSG 1
 #else
 #define HAVE_SENDMMSG 0
