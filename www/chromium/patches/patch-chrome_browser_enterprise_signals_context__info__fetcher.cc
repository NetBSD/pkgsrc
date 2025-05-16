$NetBSD: patch-chrome_browser_enterprise_signals_context__info__fetcher.cc,v 1.1 2025/05/16 16:08:17 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/enterprise/signals/context_info_fetcher.cc.orig	2025-05-05 19:21:24.000000000 +0000
+++ chrome/browser/enterprise/signals/context_info_fetcher.cc
@@ -179,6 +179,8 @@ std::vector<std::string> ContextInfoFetc
 SettingValue ContextInfoFetcher::GetOSFirewall() {
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC)
   return device_signals::GetOSFirewall();
+#elif BUILDFLAG(IS_OPENBSD)
+  return SettingValue::ENABLED;
 #elif BUILDFLAG(IS_CHROMEOS)
   return GetChromeosFirewall();
 #else
@@ -198,7 +200,7 @@ ScopedUfwConfigPathForTesting::~ScopedUf
 #endif  // BUILDFLAG(IS_LINUX)
 
 std::vector<std::string> ContextInfoFetcher::GetDnsServers() {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   return device_signals::GetSystemDnsServers();
 #else
   return std::vector<std::string>();
