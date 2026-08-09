$NetBSD: patch-net_base_network__change__notifier.cc,v 1.24 2026/08/09 06:31:19 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- net/base/network_change_notifier.cc.orig	2026-08-05 20:17:42.000000000 +0000
+++ net/base/network_change_notifier.cc
@@ -38,7 +38,7 @@
 #include "third_party/abseil-cpp/absl/container/flat_hash_set.h"
 #elif BUILDFLAG(IS_APPLE)
 #include "net/base/network_change_notifier_apple.h"
-#elif BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+#elif BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
 #include "net/base/network_change_notifier_passive.h"
 #elif BUILDFLAG(IS_FUCHSIA)
 #include "net/base/network_change_notifier_fuchsia.h"
@@ -314,7 +314,7 @@ std::unique_ptr<NetworkChangeNotifier> N
   // running network service in a separate process.
   return std::make_unique<NetworkChangeNotifierPassive>(initial_type,
                                                         initial_subtype);
-#elif BUILDFLAG(IS_CHROMEOS)
+#elif BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_NETBSD)
   return std::make_unique<NetworkChangeNotifierPassive>(initial_type,
                                                         initial_subtype);
 #elif BUILDFLAG(IS_LINUX)
@@ -325,6 +325,9 @@ std::unique_ptr<NetworkChangeNotifier> N
 #elif BUILDFLAG(IS_FUCHSIA)
   return std::make_unique<NetworkChangeNotifierFuchsia>(
       /*require_wlan=*/false);
+#elif BUILDFLAG(IS_BSD)
+  return std::make_unique<MockNetworkChangeNotifier>(
+      /*dns_config_notifier*/nullptr);
 #else
   NOTIMPLEMENTED();
   return nullptr;
