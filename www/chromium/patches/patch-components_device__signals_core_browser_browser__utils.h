$NetBSD: patch-components_device__signals_core_browser_browser__utils.h,v 1.2 2025/07/07 09:23:30 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/device_signals/core/browser/browser_utils.h.orig	2025-06-30 06:54:11.000000000 +0000
+++ components/device_signals/core/browser/browser_utils.h
@@ -36,7 +36,7 @@ bool GetSiteIsolationEnabled();
 // Returns the hostname of the current machine.
 std::string GetHostName();
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Returns the hostname of the current machine.
 std::vector<std::string> GetSystemDnsServers();
 
@@ -44,7 +44,7 @@ std::vector<std::string> GetSystemDnsSer
 SettingValue GetOSFirewall();
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Returns the path to the ufw configuration file.
 const char** GetUfwConfigPath();
 #endif  // BUILDFLAG(IS_LINUX)
