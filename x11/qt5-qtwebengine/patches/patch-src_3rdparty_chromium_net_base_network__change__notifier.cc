$NetBSD: patch-src_3rdparty_chromium_net_base_network__change__notifier.cc,v 1.1 2021/08/03 21:04:35 markd Exp $

--- src/3rdparty/chromium/net/base/network_change_notifier.cc.orig	2020-11-07 01:22:36.000000000 +0000
+++ src/3rdparty/chromium/net/base/network_change_notifier.cc
@@ -35,7 +35,7 @@
 #include "net/base/network_change_notifier_linux.h"
 #elif defined(OS_MACOSX)
 #include "net/base/network_change_notifier_mac.h"
-#elif defined(OS_CHROMEOS) || defined(OS_ANDROID)
+#elif defined(OS_CHROMEOS) || defined(OS_ANDROID) || defined(OS_BSD)
 #include "net/base/network_change_notifier_posix.h"
 #elif defined(OS_FUCHSIA)
 #include "net/base/network_change_notifier_fuchsia.h"
@@ -229,7 +229,7 @@ std::unique_ptr<NetworkChangeNotifier> N
   // service in a separate process.
   return std::make_unique<NetworkChangeNotifierPosix>(initial_type,
                                                       initial_subtype);
-#elif defined(OS_CHROMEOS)
+#elif defined(OS_CHROMEOS) || defined(OS_BSD)
   return std::make_unique<NetworkChangeNotifierPosix>(initial_type,
                                                       initial_subtype);
 #elif defined(OS_LINUX)
@@ -240,6 +240,8 @@ std::unique_ptr<NetworkChangeNotifier> N
 #elif defined(OS_FUCHSIA)
   return std::make_unique<NetworkChangeNotifierFuchsia>(
       0 /* required_features */);
+#elif defined(OS_BSD)
+  return NULL;
 #else
   NOTIMPLEMENTED();
   return NULL;
@@ -420,7 +422,7 @@ const char* NetworkChangeNotifier::Conne
   return kConnectionTypeNames[type];
 }
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 // static
 const internal::AddressTrackerLinux*
 NetworkChangeNotifier::GetAddressTracker() {
@@ -713,7 +715,7 @@ NetworkChangeNotifier::NetworkChangeNoti
   system_dns_config_notifier_->AddObserver(system_dns_config_observer_.get());
 }
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 const internal::AddressTrackerLinux*
 NetworkChangeNotifier::GetAddressTrackerInternal() const {
   return NULL;
