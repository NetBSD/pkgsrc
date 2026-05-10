$NetBSD: patch-chrome_browser_task__manager_task__manager__observer.h,v 1.19 2026/05/10 15:29:51 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/task_manager/task_manager_observer.h.orig	2026-04-28 23:05:57.000000000 +0200
+++ chrome/browser/task_manager/task_manager_observer.h
@@ -45,7 +45,7 @@ enum RefreshType {
   // or backgrounded.
   REFRESH_TYPE_PRIORITY = 1 << 12,
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   // For observers interested in getting the number of open file descriptors of
   // processes.
   REFRESH_TYPE_FD_COUNT = 1 << 13,
