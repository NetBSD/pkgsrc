$NetBSD: patch-device_gamepad_public_cpp_gamepad__features.cc,v 1.1 2026/01/19 16:14:15 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- device/gamepad/public/cpp/gamepad_features.cc.orig	2026-01-07 00:50:30.000000000 +0000
+++ device/gamepad/public/cpp/gamepad_features.cc
@@ -38,7 +38,7 @@ BASE_FEATURE(kGamepadRawInputChangeEvent
 BASE_FEATURE(kIgnorePS5GamepadsInWgi, base::FEATURE_ENABLED_BY_DEFAULT);
 #endif  // BUILDFLAG(IS_WIN)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 // Enabling this feature causes GamepadPlatformDataFetcherLinux to check device
 // IDs before opening the hidraw device node to avoid interfering with devices
 // that are not gamepads or do not require hidraw access.
