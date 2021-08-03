$NetBSD: patch-src_3rdparty_chromium_services_device_geolocation_location__arbitrator.cc,v 1.1 2021/08/03 21:04:35 markd Exp $

--- src/3rdparty/chromium/services/device/geolocation/location_arbitrator.cc.orig	2020-11-07 01:22:36.000000000 +0000
+++ src/3rdparty/chromium/services/device/geolocation/location_arbitrator.cc
@@ -160,7 +160,7 @@ LocationArbitrator::NewNetworkLocationPr
 
 std::unique_ptr<LocationProvider>
 LocationArbitrator::NewSystemLocationProvider() {
-#if defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_FUCHSIA)
+#if defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_FUCHSIA) || defined(OS_BSD)
   return nullptr;
 #else
   return device::NewSystemLocationProvider();
