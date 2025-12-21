$NetBSD: patch-src_3rdparty_chromium_net_base_network__interfaces__posix.h,v 1.1 2025/12/21 09:38:33 markd Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/net/base/network_interfaces_posix.h.orig	2024-12-17 17:58:49.000000000 +0000
+++ src/3rdparty/chromium/net/base/network_interfaces_posix.h
@@ -8,6 +8,8 @@
 // This file provides some basic functionality shared between
 // network_interfaces_linux.cc and network_interfaces_getifaddrs.cc.
 
+#include <sys/socket.h>
+
 #include <string>
 
 struct sockaddr;
