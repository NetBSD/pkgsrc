$NetBSD: patch-mozilla_netwerk_wifi_nsWifiScannerFreeBSD.cpp,v 1.4 2015/01/02 04:26:21 ryoon Exp $

--- mozilla/netwerk/wifi/nsWifiScannerFreeBSD.cpp.orig	2014-12-03 06:23:17.000000000 +0000
+++ mozilla/netwerk/wifi/nsWifiScannerFreeBSD.cpp
@@ -13,7 +13,11 @@
 #include <sys/socket.h>
 #include <net/if.h>
 #include <net/if_media.h>
+#ifdef __DragonFly__
+#include <netproto/802_11/ieee80211_ioctl.h>
+#else
 #include <net80211/ieee80211_ioctl.h>
+#endif
 
 #include <ifaddrs.h>
 #include <string.h>
