$NetBSD: patch-device_gamepad_public_cpp_gamepad__features.h,v 1.2 2026/02/15 09:04:06 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- device/gamepad/public/cpp/gamepad_features.h.orig	2026-02-03 22:07:10.000000000 +0000
+++ device/gamepad/public/cpp/gamepad_features.h
@@ -22,7 +22,7 @@ GAMEPAD_FEATURES_EXPORT BASE_DECLARE_FEA
 GAMEPAD_FEATURES_EXPORT BASE_DECLARE_FEATURE(kIgnorePS5GamepadsInWgi);
 #endif  // BUILDFLAG(IS_WIN)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 GAMEPAD_FEATURES_EXPORT BASE_DECLARE_FEATURE(kAllowlistHidrawGamepads);
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
 
