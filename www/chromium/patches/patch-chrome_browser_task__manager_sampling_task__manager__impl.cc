$NetBSD: patch-chrome_browser_task__manager_sampling_task__manager__impl.cc,v 1.14 2026/01/19 16:14:10 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/task_manager/sampling/task_manager_impl.cc.orig	2026-01-07 00:50:30.000000000 +0000
+++ chrome/browser/task_manager/sampling/task_manager_impl.cc
@@ -227,7 +227,7 @@ void TaskManagerImpl::GetUSERHandles(Tas
 }
 
 int TaskManagerImpl::GetOpenFdCount(TaskId task_id) const {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   return GetTaskGroupByTaskId(task_id)->open_fd_count();
 #else
   return -1;
