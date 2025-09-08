$NetBSD: patch-net_base_network__interfaces__posix.h,v 1.6 2025/09/08 13:24:28 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- net/base/network_interfaces_posix.h.orig	2025-08-29 18:50:09.000000000 +0000
+++ net/base/network_interfaces_posix.h
@@ -8,6 +8,8 @@
 // This file provides some basic functionality shared between
 // network_interfaces_linux.cc and network_interfaces_getifaddrs.cc.
 
+#include <sys/socket.h>
+
 #include <string>
 
 struct sockaddr;
