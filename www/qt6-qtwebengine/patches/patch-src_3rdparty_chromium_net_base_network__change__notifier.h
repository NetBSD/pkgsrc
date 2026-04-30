$NetBSD: patch-src_3rdparty_chromium_net_base_network__change__notifier.h,v 1.2 2026/04/30 06:39:41 adam Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/net/base/network_change_notifier.h.orig	2026-03-16 11:40:07.000000000 +0000
+++ src/3rdparty/chromium/net/base/network_change_notifier.h
@@ -20,7 +20,7 @@
 #include "net/base/network_handle.h"
 #include "third_party/perfetto/include/perfetto/tracing/track.h"
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "net/base/address_map_linux.h"
 #endif
 
@@ -452,7 +452,7 @@ class NET_EXPORT NetworkChangeNotifier {
   // packets sent lazily.
   static bool IsDefaultNetworkActive();
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // Returns the AddressTrackerLinux if present.
   static AddressMapOwnerLinux* GetAddressMapOwner();
 #endif
@@ -622,7 +622,7 @@ class NET_EXPORT NetworkChangeNotifier {
       SystemDnsConfigChangeNotifier* system_dns_config_notifier = nullptr,
       bool omit_observers_in_constructor_for_testing = false);
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // Returns the AddressMapOwnerLinux if present.
   virtual AddressMapOwnerLinux* GetAddressMapOwnerInternal();
 #endif
