$NetBSD: patch-chrome_browser_ui_browser__commands.cc,v 1.33 2026/11/19 19:45:54 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/browser_commands.cc.orig	2026-11-11 21:01:38.000000000 +0000
+++ chrome/browser/ui/browser_commands.cc
@@ -280,7 +280,7 @@
 #include "chrome/browser/ui/views/contextual_tasks/contextual_tasks_close_button_controller.h"
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/ui/views/scheduled_restart/scheduled_restart_bubble_controller.h"
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
 
@@ -1418,7 +1418,7 @@ void NewTabToRight(BrowserWindowInterfac
 }
 
 void NewTabFromClipboardURL(BrowserWindowInterface* browser) {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (ui::Clipboard::IsSupportedClipboardBuffer(
           ui::ClipboardBuffer::kSelection)) {
     ui::Clipboard* clipboard = ui::Clipboard::GetForCurrentThread();
@@ -2848,7 +2848,7 @@ void MaybeUpdateChrome(BrowserWindowInte
     ShowOutdatedUpgradeBubble(browser, browser,
                               /*auto_update_enabled=*/false);
   } else {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     chrome::AttemptRelaunch();
 #else
     base::RecordAction(UserMetricsAction("UpdateChrome"));
@@ -2857,7 +2857,7 @@ void MaybeUpdateChrome(BrowserWindowInte
   }
 }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void OpenScheduledRestartDialog(BrowserWindowInterface* browser) {
   if (auto* controller =
           scheduled_restart::ScheduledRestartBubbleController::From(
