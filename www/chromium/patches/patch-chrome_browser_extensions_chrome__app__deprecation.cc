$NetBSD: patch-chrome_browser_extensions_chrome__app__deprecation.cc,v 1.2 2026/09/02 13:13:23 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/extensions/chrome_app_deprecation.cc.orig	2026-08-31 22:47:51.000000000 +0000
+++ chrome/browser/extensions/chrome_app_deprecation.cc
@@ -16,7 +16,7 @@ namespace testing {
 bool g_enable_chrome_apps_for_testing = false;
 }  // namespace testing
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 bool IsExtensionUnsupportedDeprecatedApp(content::BrowserContext* context,
                                          const std::string& extension_id) {
   if (testing::g_enable_chrome_apps_for_testing) {
