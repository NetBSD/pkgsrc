$NetBSD: patch-services_device_public_cpp_device__features.cc,v 1.20 2026/06/08 13:12:45 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- services/device/public/cpp/device_features.cc.orig	2026-05-28 23:24:11.000000000 +0000
+++ services/device/public/cpp/device_features.cc
@@ -157,11 +157,11 @@ bool IsOsLevelGeolocationPermissionSuppo
 // a USB interface is busy.
 #if BUILDFLAG(IS_ANDROID)
 BASE_FEATURE(kAutomaticUsbDetach, base::FEATURE_ENABLED_BY_DEFAULT);
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kAutomaticUsbDetach, base::FEATURE_DISABLED_BY_DEFAULT);
 #endif  // BUILDFLAG(IS_ANDROID)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 // Controls whether we report the product name (like macOS and Win)
 // over the HID_NAME in the WebHID API.
 BASE_FEATURE(kProductNameOverHidName, base::FEATURE_ENABLED_BY_DEFAULT);
