$NetBSD: patch-chrome_browser_ui_browser__commands.cc,v 1.32 2026/11/08 15:38:56 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/browser_commands.cc.orig	2026-11-02 23:22:33.000000000 +0000
+++ chrome/browser/ui/browser_commands.cc
@@ -1427,7 +1427,7 @@ void NewTabToRight(BrowserWindowInterfac
 }
 
 void NewTabFromClipboardURL(BrowserWindowInterface* browser) {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (ui::Clipboard::IsSupportedClipboardBuffer(
           ui::ClipboardBuffer::kSelection)) {
     ui::Clipboard* clipboard = ui::Clipboard::GetForCurrentThread();
@@ -2866,7 +2866,7 @@ void OpenUpdateChromeDialog(BrowserWindo
     ShowOutdatedUpgradeBubble(browser, browser,
                               /*auto_update_enabled=*/false);
   } else {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     if (base::FeatureList::IsEnabled(features::kFewerUpdateConfirmations)) {
       chrome::AttemptRelaunch();
       return;
