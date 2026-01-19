$NetBSD: patch-components_device__signals_core_common_platform__utils.h,v 1.10 2026/01/19 16:14:12 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/device_signals/core/common/platform_utils.h.orig	2026-01-07 00:50:30.000000000 +0000
+++ components/device_signals/core/common/platform_utils.h
@@ -54,7 +54,7 @@ SettingValue GetSecureBootEnabled();
 std::optional<std::string> GetWindowsMachineDomain();
 #endif  // BUILDFLAG(IS_WIN)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 // Return the distribution VERSION_ID contained in
 // /etc/os-release, if it exists.
 std::optional<std::string> GetDistributionVersion();
