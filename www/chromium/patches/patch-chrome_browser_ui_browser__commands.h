$NetBSD: patch-chrome_browser_ui_browser__commands.h,v 1.1 2026/11/19 19:45:55 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/browser_commands.h.orig	2026-11-11 21:01:38.000000000 +0000
+++ chrome/browser/ui/browser_commands.h
@@ -352,7 +352,7 @@ void ToggleShowSearchTools(BrowserWindow
 void ShowAppMenu(BrowserWindowInterface* browser);
 void ShowAvatarMenu(BrowserWindowInterface* browser);
 void MaybeUpdateChrome(BrowserWindowInterface* browser);
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void OpenScheduledRestartDialog(BrowserWindowInterface* browser);
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
 bool CanRequestTabletSite(content::WebContents* current_tab);
