$NetBSD: patch-services_device_public_cpp_device__features.h,v 1.5 2025/09/08 13:24:30 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- services/device/public/cpp/device_features.h.orig	2025-08-29 18:50:09.000000000 +0000
+++ services/device/public/cpp/device_features.h
@@ -53,7 +53,7 @@ extern const DEVICE_FEATURES_EXPORT
 
 DEVICE_FEATURES_EXPORT bool IsOsLevelGeolocationPermissionSupportEnabled();
 
-#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 DEVICE_FEATURES_EXPORT BASE_DECLARE_FEATURE(kAutomaticUsbDetach);
 #endif  // BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX)
 
