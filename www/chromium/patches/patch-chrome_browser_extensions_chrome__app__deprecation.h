$NetBSD: patch-chrome_browser_extensions_chrome__app__deprecation.h,v 1.1 2026/08/09 06:31:08 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/extensions/chrome_app_deprecation.h.orig	2026-08-05 20:17:42.000000000 +0000
+++ chrome/browser/extensions/chrome_app_deprecation.h
@@ -24,7 +24,7 @@ namespace testing {
 extern bool g_enable_chrome_apps_for_testing;
 }  // namespace testing
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Returns whether the extension with `extension_id` is an unsupported
 // deprecated app (hosted app, legacy packaged app, or platform app) on
 // Windows/Mac/Linux.
