$NetBSD: patch-src_3rdparty_chromium_net_base_address__tracker__linux.h,v 1.1 2021/08/03 21:04:35 markd Exp $

--- src/3rdparty/chromium/net/base/address_tracker_linux.h.orig	2020-07-08 21:40:46.000000000 +0000
+++ src/3rdparty/chromium/net/base/address_tracker_linux.h
@@ -6,10 +6,6 @@
 #define NET_BASE_ADDRESS_TRACKER_LINUX_H_
 
 #include <sys/socket.h>  // Needed to include netlink.
-// Mask superfluous definition of |struct net|. This is fixed in Linux 2.6.38.
-#define net net_kernel
-#include <linux/rtnetlink.h>
-#undef net
 #include <stddef.h>
 
 #include <map>
