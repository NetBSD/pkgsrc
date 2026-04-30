$NetBSD: patch-src_3rdparty_chromium_services_device_geolocation_location__provider__manager.cc,v 1.2 2026/04/30 06:39:42 adam Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/services/device/geolocation/location_provider_manager.cc.orig	2026-03-16 11:40:07.000000000 +0000
+++ src/3rdparty/chromium/services/device/geolocation/location_provider_manager.cc
@@ -86,7 +86,7 @@ LocationProviderManager::LocationProvide
 #if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_IOS)
   // On Android and iOS, default to using the platform location provider.
   provider_manager_mode_ = LPMM::kPlatformOnly;
-#elif BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // On Ash / Lacros / Linux, default to using the network location provider.
   provider_manager_mode_ = LPMM::kNetworkOnly;
 #else
