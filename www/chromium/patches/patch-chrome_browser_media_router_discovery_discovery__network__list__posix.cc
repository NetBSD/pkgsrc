$NetBSD: patch-chrome_browser_media_router_discovery_discovery__network__list__posix.cc,v 1.33 2026/11/19 19:45:53 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/media/router/discovery/discovery_network_list_posix.cc.orig	2026-11-11 21:01:38.000000000 +0000
+++ chrome/browser/media/router/discovery/discovery_network_list_posix.cc
@@ -5,11 +5,12 @@
 #include "chrome/browser/media/router/discovery/discovery_network_list.h"
 
 #include <ifaddrs.h>
+#include <sys/socket.h>
+#include <sys/types.h>
+#include <sys/time.h>
 #include <net/if.h>
 #include <net/if_arp.h>
 #include <netinet/in.h>
-#include <sys/socket.h>
-#include <sys/types.h>
 
 #include <algorithm>
 #include <optional>
@@ -24,7 +25,7 @@
 #include "chrome/browser/media/router/discovery/discovery_network_list_wifi.h"
 #endif
 
-#if !BUILDFLAG(IS_MAC)
+#if !BUILDFLAG(IS_MAC) && !BUILDFLAG(IS_BSD)
 #include <netpacket/packet.h>
 #else
 #include <net/if_dl.h>
@@ -33,7 +34,7 @@
 namespace media_router {
 namespace {
 
-#if !BUILDFLAG(IS_MAC)
+#if !BUILDFLAG(IS_MAC) && !BUILDFLAG(IS_BSD)
 using sll = struct sockaddr_ll;
 #define SOCKET_ARP_TYPE(s) ((s)->sll_hatype)
 #define SOCKET_ADDRESS_LEN(s) ((s)->sll_halen)
