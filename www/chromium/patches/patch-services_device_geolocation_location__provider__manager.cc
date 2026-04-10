$NetBSD: patch-services_device_geolocation_location__provider__manager.cc,v 1.17 2026/04/10 17:31:58 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- services/device/geolocation/location_provider_manager.cc.orig	2026-04-06 16:25:54.000000000 +0000
+++ services/device/geolocation/location_provider_manager.cc
@@ -91,7 +91,7 @@ LocationProviderManager::LocationProvide
 #if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_IOS)
   // On Android and iOS, default to using the platform location provider.
   provider_manager_mode_ = kPlatformOnly;
-#elif BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // On Ash / Lacros / Linux, default to using the network location provider.
   provider_manager_mode_ = kNetworkOnly;
 #else
