$NetBSD: patch-services_device_public_cpp_device__features.cc,v 1.5 2025/09/08 13:24:30 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- services/device/public/cpp/device_features.cc.orig	2025-08-29 18:50:09.000000000 +0000
+++ services/device/public/cpp/device_features.cc
@@ -144,7 +144,7 @@ bool IsOsLevelGeolocationPermissionSuppo
 BASE_FEATURE(kAutomaticUsbDetach,
              "AutomaticUsbDetach",
              base::FEATURE_ENABLED_BY_DEFAULT);
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kAutomaticUsbDetach,
              "AutomaticUsbDetach",
              base::FEATURE_DISABLED_BY_DEFAULT);
