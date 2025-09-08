$NetBSD: patch-chrome_browser_ui_task__manager_task__manager__columns.h,v 1.5 2025/09/08 13:24:20 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/task_manager/task_manager_columns.h.orig	2025-08-29 18:50:09.000000000 +0000
+++ chrome/browser/ui/task_manager/task_manager_columns.h
@@ -264,7 +264,7 @@ inline constexpr std::array kColumns = {
                     .default_visibility = false},
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
     TableColumnData{.id = IDS_TASK_MANAGER_OPEN_FD_COUNT_COLUMN,
                     .align = ui::TableColumn::RIGHT,
                     .width = -1,
