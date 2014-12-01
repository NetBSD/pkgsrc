$NetBSD: patch-netwerk_wifi_nsWifiScannerFreeBSD.cpp,v 1.6 2014/12/01 18:11:14 ryoon Exp $

--- netwerk/wifi/nsWifiScannerFreeBSD.cpp.orig	2014-11-21 03:37:47.000000000 +0000
+++ netwerk/wifi/nsWifiScannerFreeBSD.cpp
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
