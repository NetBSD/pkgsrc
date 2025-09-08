$NetBSD: patch-chrome_browser_ui_views_frame_system__menu__model__builder.cc,v 1.6 2025/09/08 13:24:20 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/views/frame/system_menu_model_builder.cc.orig	2025-08-29 18:50:09.000000000 +0000
+++ chrome/browser/ui/views/frame/system_menu_model_builder.cc
@@ -74,7 +74,7 @@ void SystemMenuModelBuilder::BuildMenu(u
 
 void SystemMenuModelBuilder::BuildSystemMenuForBrowserWindow(
     ui::SimpleMenuModel* model) {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   model->AddItemWithStringId(IDC_MINIMIZE_WINDOW, IDS_MINIMIZE_WINDOW_MENU);
   model->AddItemWithStringId(IDC_MAXIMIZE_WINDOW, IDS_MAXIMIZE_WINDOW_MENU);
   model->AddItemWithStringId(IDC_RESTORE_WINDOW, IDS_RESTORE_WINDOW_MENU);
@@ -100,7 +100,7 @@ void SystemMenuModelBuilder::BuildSystem
     model->AddSeparator(ui::NORMAL_SEPARATOR);
     model->AddItemWithStringId(IDC_TASK_MANAGER_CONTEXT_MENU, IDS_TASK_MANAGER);
   }
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   model->AddSeparator(ui::NORMAL_SEPARATOR);
   bool supports_server_side_decorations = true;
 #if BUILDFLAG(IS_OZONE) && !BUILDFLAG(IS_CHROMEOS)
@@ -174,7 +174,7 @@ void SystemMenuModelBuilder::BuildSystem
     model->AddSeparator(ui::NORMAL_SEPARATOR);
     model->AddItemWithStringId(IDC_TASK_MANAGER, IDS_TASK_MANAGER);
   }
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   model->AddSeparator(ui::NORMAL_SEPARATOR);
   model->AddItemWithStringId(IDC_CLOSE_WINDOW, IDS_CLOSE);
 #endif
