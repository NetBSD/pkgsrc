$NetBSD: patch-chrome_browser_task__manager_sampling_task__manager__impl.cc,v 1.1 2025/02/06 09:57:52 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/task_manager/sampling/task_manager_impl.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ chrome/browser/task_manager/sampling/task_manager_impl.cc
@@ -219,7 +219,7 @@ void TaskManagerImpl::GetUSERHandles(Tas
 }
 
 int TaskManagerImpl::GetOpenFdCount(TaskId task_id) const {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   return GetTaskGroupByTaskId(task_id)->open_fd_count();
 #else
   return -1;
