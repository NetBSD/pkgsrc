$NetBSD: patch-chrome_browser_media_router_discovery_discovery__network__list__wifi__linux.cc,v 1.1 2025/02/06 09:57:48 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/media/router/discovery/discovery_network_list_wifi_linux.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ chrome/browser/media/router/discovery/discovery_network_list_wifi_linux.cc
@@ -9,7 +9,11 @@
 #include <sys/socket.h>
 #include <sys/types.h>
 
+#include "build/build_config.h"
+
+#if !BUILDFLAG(IS_BSD)
 #include <linux/wireless.h>
+#endif
 
 #include "base/check.h"
 #include "base/files/scoped_file.h"
@@ -20,6 +24,7 @@ namespace media_router {
 bool MaybeGetWifiSSID(const std::string& if_name, std::string* ssid_out) {
   DCHECK(ssid_out);
 
+#if !BUILDFLAG(IS_BSD)
   base::ScopedFD ioctl_socket(socket(AF_INET, SOCK_DGRAM, 0));
   if (!ioctl_socket.is_valid()) {
     // AF_INET is for IPv4, so it may fail for IPv6-only hosts even when there
@@ -41,6 +46,7 @@ bool MaybeGetWifiSSID(const std::string&
     ssid_out->assign(ssid);
     return true;
   }
+#endif
   return false;
 }
 
