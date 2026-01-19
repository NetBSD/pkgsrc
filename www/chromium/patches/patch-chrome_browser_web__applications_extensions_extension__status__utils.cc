$NetBSD: patch-chrome_browser_web__applications_extensions_extension__status__utils.cc,v 1.14 2026/01/19 16:14:11 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/web_applications/extensions/extension_status_utils.cc.orig	2026-01-07 00:50:30.000000000 +0000
+++ chrome/browser/web_applications/extensions/extension_status_utils.cc
@@ -94,7 +94,7 @@ bool IsExternalExtensionUninstalled(cont
   return prefs && prefs->IsExternalExtensionUninstalled(extension_id);
 }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 bool IsExtensionUnsupportedDeprecatedApp(content::BrowserContext* context,
                                          const std::string& extension_id) {
   if (testing::g_enable_chrome_apps_for_testing) {
