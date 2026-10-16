$NetBSD: patch-chrome_browser_ui_views_scheduled__restart_scheduled__restart__bubble__controller.cc,v 1.2 2026/10/16 15:30:48 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/views/scheduled_restart/scheduled_restart_bubble_controller.cc.orig	2026-10-14 21:09:54.000000000 +0000
+++ chrome/browser/ui/views/scheduled_restart/scheduled_restart_bubble_controller.cc
@@ -164,7 +164,7 @@ ScheduledRestartBubbleController::GetSch
   if (scheduled_restart_manager_for_testing_) {
     return scheduled_restart_manager_for_testing_;
   }
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return g_browser_process && g_browser_process->GetFeatures()
              ? g_browser_process->GetFeatures()->scheduled_restart_manager()
              : nullptr;
