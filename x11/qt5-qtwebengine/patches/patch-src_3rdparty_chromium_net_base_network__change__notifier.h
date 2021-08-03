$NetBSD: patch-src_3rdparty_chromium_net_base_network__change__notifier.h,v 1.1 2021/08/03 21:04:35 markd Exp $

--- src/3rdparty/chromium/net/base/network_change_notifier.h.orig	2020-07-15 18:56:47.000000000 +0000
+++ src/3rdparty/chromium/net/base/network_change_notifier.h
@@ -23,7 +23,7 @@ struct NetworkInterface;
 class SystemDnsConfigChangeNotifier;
 typedef std::vector<NetworkInterface> NetworkInterfaceList;
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 namespace internal {
 class AddressTrackerLinux;
 }
@@ -366,7 +366,7 @@ class NET_EXPORT NetworkChangeNotifier {
   // Chrome net code.
   static SystemDnsConfigChangeNotifier* GetSystemDnsConfigNotifier();
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // Returns the AddressTrackerLinux if present.
   static const internal::AddressTrackerLinux* GetAddressTracker();
 #endif
@@ -513,7 +513,7 @@ class NET_EXPORT NetworkChangeNotifier {
           NetworkChangeCalculatorParams(),
       SystemDnsConfigChangeNotifier* system_dns_config_notifier = nullptr);
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // Returns the AddressTrackerLinux if present.
   // TODO(szym): Retrieve AddressMap from NetworkState. http://crbug.com/144212
   virtual const internal::AddressTrackerLinux*
