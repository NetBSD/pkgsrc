$NetBSD: patch-src_3rdparty_chromium_services_device_public_cpp_device__features.cc,v 1.1 2026/04/30 06:39:42 adam Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/services/device/public/cpp/device_features.cc.orig	2026-03-16 11:40:07.000000000 +0000
+++ src/3rdparty/chromium/services/device/public/cpp/device_features.cc
@@ -147,7 +147,7 @@ bool IsOsLevelGeolocationPermissionSuppo
 BASE_FEATURE(kAutomaticUsbDetach,
              "AutomaticUsbDetach",
              base::FEATURE_ENABLED_BY_DEFAULT);
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kAutomaticUsbDetach,
              "AutomaticUsbDetach",
              base::FEATURE_DISABLED_BY_DEFAULT);
