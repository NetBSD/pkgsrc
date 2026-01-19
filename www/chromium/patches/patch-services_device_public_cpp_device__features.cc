$NetBSD: patch-services_device_public_cpp_device__features.cc,v 1.13 2026/01/19 16:14:19 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- services/device/public/cpp/device_features.cc.orig	2026-01-07 00:50:30.000000000 +0000
+++ services/device/public/cpp/device_features.cc
@@ -131,7 +131,7 @@ bool IsOsLevelGeolocationPermissionSuppo
 // a USB interface is busy.
 #if BUILDFLAG(IS_ANDROID)
 BASE_FEATURE(kAutomaticUsbDetach, base::FEATURE_ENABLED_BY_DEFAULT);
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kAutomaticUsbDetach, base::FEATURE_DISABLED_BY_DEFAULT);
 #endif  // BUILDFLAG(IS_ANDROID)
 
