$NetBSD: patch-src_3rdparty_chromium_components_device__signals_core_common_platform__utils.h,v 1.1 2026/04/30 06:39:37 adam Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/components/device_signals/core/common/platform_utils.h.orig	2026-03-16 11:40:07.000000000 +0000
+++ src/3rdparty/chromium/components/device_signals/core/common/platform_utils.h
@@ -57,7 +57,7 @@ SettingValue GetSecureBootEnabled();
 std::optional<std::string> GetWindowsMachineDomain();
 #endif  // BUILDFLAG(IS_WIN)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 // Return the distribution VERSION_ID contained in
 // /etc/os-release, if it exists.
 std::optional<std::string> GetDistributionVersion();
