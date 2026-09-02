$NetBSD: patch-services_device_public_cpp_device__features.cc,v 1.24 2026/09/02 13:13:34 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- services/device/public/cpp/device_features.cc.orig	2026-08-31 22:47:51.000000000 +0000
+++ services/device/public/cpp/device_features.cc
@@ -177,11 +177,11 @@ bool IsOsLevelGeolocationPermissionSuppo
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
