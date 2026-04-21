$NetBSD: patch-device_gamepad_public_cpp_gamepad__features.h,v 1.5 2026/04/21 15:21:16 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- device/gamepad/public/cpp/gamepad_features.h.orig	2026-04-14 23:31:37.000000000 +0200
+++ device/gamepad/public/cpp/gamepad_features.h
@@ -22,7 +22,7 @@ GAMEPAD_FEATURES_EXPORT BASE_DECLARE_FEA
 GAMEPAD_FEATURES_EXPORT BASE_DECLARE_FEATURE(kIgnorePS5GamepadsInWgi);
 #endif  // BUILDFLAG(IS_WIN)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 GAMEPAD_FEATURES_EXPORT BASE_DECLARE_FEATURE(kAllowlistHidrawGamepads);
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
 
