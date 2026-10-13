$NetBSD: patch-services_device_geolocation_location__provider__manager.cc,v 1.29 2026/10/13 13:16:46 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- services/device/geolocation/location_provider_manager.cc.orig	2026-10-06 00:06:58.000000000 +0000
+++ services/device/geolocation/location_provider_manager.cc
@@ -392,7 +392,7 @@ LocationProviderManager::NewSystemLocati
   return device::NewSystemLocationProvider(
       geolocation_system_permission_manager_->GetSystemGeolocationSource());
 #elif BUILDFLAG(IS_WIN) || BUILDFLAG(IS_ANDROID) || \
-    (BUILDFLAG(IS_LINUX) && BUILDFLAG(USE_DBUS))
+    ((BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && BUILDFLAG(USE_DBUS))
   return device::NewSystemLocationProvider();
 #else
   return nullptr;
