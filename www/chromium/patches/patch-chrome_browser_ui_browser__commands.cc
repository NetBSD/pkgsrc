$NetBSD: patch-chrome_browser_ui_browser__commands.cc,v 1.30 2026/10/16 15:30:46 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/browser_commands.cc.orig	2026-10-14 21:09:54.000000000 +0000
+++ chrome/browser/ui/browser_commands.cc
@@ -1414,7 +1414,7 @@ void NewTabToRight(BrowserWindowInterfac
 }
 
 void NewTabFromClipboardURL(BrowserWindowInterface* browser) {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (ui::Clipboard::IsSupportedClipboardBuffer(
           ui::ClipboardBuffer::kSelection)) {
     ui::Clipboard* clipboard = ui::Clipboard::GetForCurrentThread();
@@ -2774,7 +2774,7 @@ void OpenUpdateChromeDialog(BrowserWindo
     ShowOutdatedUpgradeBubble(browser, browser,
                               /*auto_update_enabled=*/false);
   } else {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     if (base::FeatureList::IsEnabled(features::kFewerUpdateConfirmations)) {
       chrome::AttemptRelaunch();
       return;
