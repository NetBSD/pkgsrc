$NetBSD: patch-services_device_public_cpp_device__features.h,v 1.24 2026/09/02 13:13:34 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- services/device/public/cpp/device_features.h.orig	2026-08-31 22:47:51.000000000 +0000
+++ services/device/public/cpp/device_features.h
@@ -65,11 +65,11 @@ extern const DEVICE_FEATURES_EXPORT
 
 DEVICE_FEATURES_EXPORT bool IsOsLevelGeolocationPermissionSupportEnabled();
 
-#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 DEVICE_FEATURES_EXPORT BASE_DECLARE_FEATURE(kAutomaticUsbDetach);
 #endif  // BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 DEVICE_FEATURES_EXPORT BASE_DECLARE_FEATURE(kProductNameOverHidName);
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
 
