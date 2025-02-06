$NetBSD: patch-chrome_browser_ui_task__manager_task__manager__columns.cc,v 1.1 2025/02/06 09:57:53 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/task_manager/task_manager_columns.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ chrome/browser/ui/task_manager/task_manager_columns.cc
@@ -93,7 +93,7 @@ const TableColumnData kColumns[] = {
      std::size("100000") * kCharWidth, -1, true, false, false},
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
     {IDS_TASK_MANAGER_OPEN_FD_COUNT_COLUMN, ui::TableColumn::RIGHT, -1, 0,
      std::size("999") * kCharWidth, -1, true, false, false},
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC)
