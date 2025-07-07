$NetBSD: patch-services_device_public_cpp_device__features.cc,v 1.2 2025/07/07 09:23:36 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- services/device/public/cpp/device_features.cc.orig	2025-06-30 06:54:11.000000000 +0000
+++ services/device/public/cpp/device_features.cc
@@ -140,7 +140,7 @@ bool IsOsLevelGeolocationPermissionSuppo
 
 // Controls whether Chrome will try to automatically detach kernel drivers when
 // a USB interface is busy.
-#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kAutomaticUsbDetach,
              "AutomaticUsbDetach",
              base::FEATURE_DISABLED_BY_DEFAULT);
