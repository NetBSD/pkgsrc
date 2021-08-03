$NetBSD: patch-src_3rdparty_chromium_net_socket_udp__socket__posix.h,v 1.1 2021/08/03 21:04:35 markd Exp $

--- src/3rdparty/chromium/net/socket/udp_socket_posix.h.orig	2020-07-15 18:56:00.000000000 +0000
+++ src/3rdparty/chromium/net/socket/udp_socket_posix.h
@@ -34,7 +34,7 @@
 
 #if defined(__ANDROID__) && defined(__aarch64__)
 #define HAVE_SENDMMSG 1
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
 #define HAVE_SENDMMSG 1
 #else
 #define HAVE_SENDMMSG 0
