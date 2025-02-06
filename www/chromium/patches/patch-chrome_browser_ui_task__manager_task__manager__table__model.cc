$NetBSD: patch-chrome_browser_ui_task__manager_task__manager__table__model.cc,v 1.1 2025/02/06 09:57:53 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/task_manager/task_manager_table_model.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ chrome/browser/ui/task_manager/task_manager_table_model.cc
@@ -459,7 +459,7 @@ std::u16string TaskManagerTableModel::Ge
           ? stringifier_->backgrounded_string()
           : stringifier_->foregrounded_string();
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
     case IDS_TASK_MANAGER_OPEN_FD_COUNT_COLUMN: {
       const int fd_count = observed_task_manager()->GetOpenFdCount(tasks_[row]);
       return fd_count >= 0 ? base::FormatNumber(fd_count)
@@ -626,7 +626,7 @@ int TaskManagerTableModel::CompareValues
       return BooleanCompare(is_proc1_bg, is_proc2_bg);
     }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
     case IDS_TASK_MANAGER_OPEN_FD_COUNT_COLUMN: {
       const int proc1_fd_count =
           observed_task_manager()->GetOpenFdCount(tasks_[row1]);
@@ -811,7 +811,7 @@ void TaskManagerTableModel::UpdateRefres
       type = REFRESH_TYPE_KEEPALIVE_COUNT;
       break;
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
     case IDS_TASK_MANAGER_OPEN_FD_COUNT_COLUMN:
       type = REFRESH_TYPE_FD_COUNT;
       break;
