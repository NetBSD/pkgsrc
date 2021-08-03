$NetBSD: patch-src_3rdparty_chromium_net_base_network__interfaces__posix.h,v 1.1 2021/08/03 21:04:35 markd Exp $

--- src/3rdparty/chromium/net/base/network_interfaces_posix.h.orig	2020-07-15 18:56:00.000000000 +0000
+++ src/3rdparty/chromium/net/base/network_interfaces_posix.h
@@ -8,6 +8,8 @@
 // This file provides some basic functionality shared between
 // network_interfaces_linux.cc and network_interfaces_getifaddrs.cc.
 
+#include <sys/socket.h>
+
 #include <string>
 
 struct sockaddr;
