$NetBSD: patch-net_base_network__interfaces__posix.h,v 1.14 2026/01/19 16:14:17 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- net/base/network_interfaces_posix.h.orig	2026-01-07 00:50:30.000000000 +0000
+++ net/base/network_interfaces_posix.h
@@ -8,6 +8,8 @@
 // This file provides some basic functionality shared between
 // network_interfaces_linux.cc and network_interfaces_getifaddrs.cc.
 
+#include <sys/socket.h>
+
 #include <string>
 
 struct sockaddr;
