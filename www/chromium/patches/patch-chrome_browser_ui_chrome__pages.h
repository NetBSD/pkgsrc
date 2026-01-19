$NetBSD: patch-chrome_browser_ui_chrome__pages.h,v 1.14 2026/01/19 16:14:10 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/chrome_pages.h.orig	2026-01-07 00:50:30.000000000 +0000
+++ chrome/browser/ui/chrome_pages.h
@@ -39,7 +39,7 @@ namespace signin {
 enum class ConsentLevel;
 }  // namespace signin
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 namespace web_app {
 enum class AppSettingsPageEntryPoint;
 }  // namespace web_app
@@ -185,7 +185,7 @@ void ShowShortcutCustomizationApp(Profil
                                   const std::string& category);
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Show chrome://app-settings/<app-id> page.
 void ShowWebAppSettings(Browser* browser,
                         const std::string& app_id,
