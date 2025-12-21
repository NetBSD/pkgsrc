$NetBSD: patch-src_3rdparty_chromium_services_device_geolocation_location__provider__manager.cc,v 1.1 2025/12/21 09:38:36 markd Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/services/device/geolocation/location_provider_manager.cc.orig	2025-09-25 11:10:42.000000000 +0000
+++ src/3rdparty/chromium/services/device/geolocation/location_provider_manager.cc
@@ -47,7 +47,7 @@ LocationProviderManager::LocationProvide
 #if BUILDFLAG(IS_ANDROID)
   // On Android, default to using the platform location provider.
   provider_manager_mode_ = LPMM::kPlatformOnly;
-#elif BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // On Ash / Lacros / Linux, default to using the network location provider.
   provider_manager_mode_ = LPMM::kNetworkOnly;
 #else
