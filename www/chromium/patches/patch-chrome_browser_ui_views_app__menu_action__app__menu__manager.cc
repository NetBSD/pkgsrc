$NetBSD: patch-chrome_browser_ui_views_app__menu_action__app__menu__manager.cc,v 1.1 2026/11/19 19:45:55 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/views/app_menu/action_app_menu_manager.cc.orig	2026-11-11 21:01:38.000000000 +0000
+++ chrome/browser/ui/views/app_menu/action_app_menu_manager.cc
@@ -40,7 +40,7 @@
 #include "chrome/browser/ui/tabs/tab_strip_model.h"
 #include "ui/base/class_property.h"
 #include "ui/base/models/menu_separator_types.h"
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/global_features.h"
 #include "chrome/browser/lifetime/scheduled_restart_manager.h"
 #endif
@@ -552,7 +552,7 @@ void ActionAppMenuManager::AddNotificati
                 kActionUpgradeDialog,
                 {.minor_text =
                      AppMenuModel::GetUpgradeDialogSubstringText()})) {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
           actions::ActionItem* scheduled_restart_action =
               actions::ActionManager::Get().FindAction(
                   kActionScheduledRestartDialog, scope);
