$NetBSD: patch-chrome_browser_ui_chrome__pages.cc,v 1.1 2025/02/06 09:57:52 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/chrome_pages.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ chrome/browser/ui/chrome_pages.cc
@@ -87,7 +87,7 @@
 #include "components/signin/public/identity_manager/identity_manager.h"
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/web_applications/web_app_utils.h"
 #endif
 
@@ -380,7 +380,7 @@ void ShowChromeTips(Browser* browser) {
   ShowSingletonTab(browser, GURL(kChromeTipsURL));
 }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void ShowChromeWhatsNew(Browser* browser) {
   ShowSingletonTab(browser, GURL(kChromeUIWhatsNewURL));
 }
@@ -726,7 +726,7 @@ void ShowShortcutCustomizationApp(Profil
 #endif  // BUILDFLAG(IS_CHROMEOS_ASH)
 }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void ShowWebAppSettingsImpl(Browser* browser,
                             Profile* profile,
                             const std::string& app_id,
