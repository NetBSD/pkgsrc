$NetBSD: patch-src_3rdparty_chromium_net_base_network__change__notifier.cc,v 1.2 2022/04/18 11:18:19 adam Exp $

--- src/3rdparty/chromium/net/base/network_change_notifier.cc.orig	2021-02-19 16:41:59.000000000 +0000
+++ src/3rdparty/chromium/net/base/network_change_notifier.cc
@@ -36,7 +36,7 @@
 #include "net/base/network_change_notifier_linux.h"
 #elif defined(OS_APPLE)
 #include "net/base/network_change_notifier_mac.h"
-#elif defined(OS_CHROMEOS) || defined(OS_ANDROID)
+#elif defined(OS_CHROMEOS) || defined(OS_ANDROID) || defined(OS_BSD)
 #include "net/base/network_change_notifier_posix.h"
 #elif defined(OS_FUCHSIA)
 #include "net/base/network_change_notifier_fuchsia.h"
@@ -238,7 +238,7 @@ std::unique_ptr<NetworkChangeNotifier> N
   // service in a separate process.
   return std::make_unique<NetworkChangeNotifierPosix>(initial_type,
                                                       initial_subtype);
-#elif defined(OS_CHROMEOS)
+#elif defined(OS_CHROMEOS) || defined(OS_BSD)
   return std::make_unique<NetworkChangeNotifierPosix>(initial_type,
                                                       initial_subtype);
 #elif defined(OS_LINUX)
@@ -249,6 +249,8 @@ std::unique_ptr<NetworkChangeNotifier> N
 #elif defined(OS_FUCHSIA)
   return std::make_unique<NetworkChangeNotifierFuchsia>(
       fuchsia::hardware::ethernet::Features());
+#elif defined(OS_BSD)
+  return NULL;
 #else
   NOTIMPLEMENTED();
   return NULL;
@@ -424,7 +426,7 @@ const char* NetworkChangeNotifier::Conne
   return kConnectionTypeNames[type];
 }
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 // static
 const internal::AddressTrackerLinux*
 NetworkChangeNotifier::GetAddressTracker() {
@@ -728,7 +730,7 @@ NetworkChangeNotifier::NetworkChangeNoti
   can_add_observers_ = true;
 }
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 const internal::AddressTrackerLinux*
 NetworkChangeNotifier::GetAddressTrackerInternal() const {
   return NULL;
