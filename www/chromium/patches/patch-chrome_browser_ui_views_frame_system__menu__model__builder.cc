$NetBSD: patch-chrome_browser_ui_views_frame_system__menu__model__builder.cc,v 1.27 2026/09/29 07:42:51 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/views/frame/system_menu_model_builder.cc.orig	2026-09-22 00:09:16.000000000 +0000
+++ chrome/browser/ui/views/frame/system_menu_model_builder.cc
@@ -139,7 +139,7 @@ void SystemMenuModelBuilder::BuildSystem
   }
 #endif  // BUILDFLAG(IS_WIN)
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   AddItemWithIconMaybe(model, IDC_MINIMIZE_WINDOW, IDS_MINIMIZE_WINDOW_MENU,
                        views::kChromeMinimizeIcon);
   AddItemWithIconMaybe(model, IDC_MAXIMIZE_WINDOW, IDS_MAXIMIZE_WINDOW_MENU,
@@ -265,7 +265,7 @@ void SystemMenuModelBuilder::BuildSystem
     model->AddItemWithStringId(IDC_TASK_MANAGER_CONTEXT_MENU,
                                task_manager_string_id);
   }
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   model->AddSeparator(ui::NORMAL_SEPARATOR);
   bool supports_server_side_decorations = true;
 #if BUILDFLAG(IS_OZONE) && !BUILDFLAG(IS_CHROMEOS)
@@ -358,7 +358,7 @@ void SystemMenuModelBuilder::BuildSystem
 #endif
     model->AddItemWithStringId(IDC_TASK_MANAGER, task_manager_string_id);
   }
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   model->AddSeparator(ui::NORMAL_SEPARATOR);
   model->AddItemWithStringId(IDC_CLOSE_WINDOW, IDS_CLOSE);
 #endif
