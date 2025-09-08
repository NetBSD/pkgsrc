$NetBSD: patch-components_device__signals_core_common_platform__utils.h,v 1.1 2025/09/08 13:13:47 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/device_signals/core/common/platform_utils.h.orig	2025-08-29 18:50:09.000000000 +0000
+++ components/device_signals/core/common/platform_utils.h
@@ -57,7 +57,7 @@ SettingValue GetSecureBootEnabled();
 std::optional<std::string> GetWindowsMachineDomain();
 #endif  // BUILDFLAG(IS_WIN)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 // Return the distribution VERSION_ID contained in
 // /etc/os-release, if it exists.
 std::optional<std::string> GetDistributionVersion();
