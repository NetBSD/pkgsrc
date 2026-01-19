$NetBSD: patch-net_base_network__change__notifier.h,v 1.14 2026/01/19 16:14:17 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- net/base/network_change_notifier.h.orig	2026-01-07 00:50:30.000000000 +0000
+++ net/base/network_change_notifier.h
@@ -20,7 +20,7 @@
 #include "net/base/network_handle.h"
 #include "third_party/perfetto/include/perfetto/tracing/track.h"
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "net/base/address_map_linux.h"
 #endif
 
@@ -459,7 +459,7 @@ class NET_EXPORT NetworkChangeNotifier {
   // packets sent lazily.
   static bool IsDefaultNetworkActive();
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // Returns the AddressTrackerLinux if present.
   static AddressMapOwnerLinux* GetAddressMapOwner();
 #endif
@@ -634,7 +634,7 @@ class NET_EXPORT NetworkChangeNotifier {
       SystemDnsConfigChangeNotifier* system_dns_config_notifier = nullptr,
       bool omit_observers_in_constructor_for_testing = false);
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // Returns the AddressMapOwnerLinux if present.
   virtual AddressMapOwnerLinux* GetAddressMapOwnerInternal();
 #endif
