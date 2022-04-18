$NetBSD: patch-src_3rdparty_chromium_net_base_network__change__notifier.h,v 1.2 2022/04/18 11:18:19 adam Exp $

--- src/3rdparty/chromium/net/base/network_change_notifier.h.orig	2021-02-19 16:41:59.000000000 +0000
+++ src/3rdparty/chromium/net/base/network_change_notifier.h
@@ -23,7 +23,7 @@ struct NetworkInterface;
 class SystemDnsConfigChangeNotifier;
 typedef std::vector<NetworkInterface> NetworkInterfaceList;
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 namespace internal {
 class AddressTrackerLinux;
 }
@@ -370,7 +370,7 @@ class NET_EXPORT NetworkChangeNotifier {
   // Chrome net code.
   static SystemDnsConfigChangeNotifier* GetSystemDnsConfigNotifier();
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   // Returns the AddressTrackerLinux if present.
   static const internal::AddressTrackerLinux* GetAddressTracker();
 #endif
@@ -522,7 +522,7 @@ class NET_EXPORT NetworkChangeNotifier {
       SystemDnsConfigChangeNotifier* system_dns_config_notifier = nullptr,
       bool omit_observers_in_constructor_for_testing = false);
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   // Returns the AddressTrackerLinux if present.
   // TODO(szym): Retrieve AddressMap from NetworkState. http://crbug.com/144212
   virtual const internal::AddressTrackerLinux*
