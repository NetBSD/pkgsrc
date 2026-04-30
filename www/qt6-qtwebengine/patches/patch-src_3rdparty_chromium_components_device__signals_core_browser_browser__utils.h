$NetBSD: patch-src_3rdparty_chromium_components_device__signals_core_browser_browser__utils.h,v 1.1 2026/04/30 06:39:37 adam Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/components/device_signals/core/browser/browser_utils.h.orig	2026-03-16 11:40:07.000000000 +0000
+++ src/3rdparty/chromium/components/device_signals/core/browser/browser_utils.h
@@ -38,7 +38,7 @@ bool GetSiteIsolationEnabled();
 std::string GetHostName();
 #endif  // !BUILDFLAG(IS_ANDROID)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Returns the hostname of the current machine.
 std::vector<std::string> GetSystemDnsServers();
 
@@ -46,7 +46,7 @@ std::vector<std::string> GetSystemDnsSer
 SettingValue GetOSFirewall();
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Returns the path to the ufw configuration file.
 const char** GetUfwConfigPath();
 #endif  // BUILDFLAG(IS_LINUX)
