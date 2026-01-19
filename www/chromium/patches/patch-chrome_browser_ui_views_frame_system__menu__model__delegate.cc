$NetBSD: patch-chrome_browser_ui_views_frame_system__menu__model__delegate.cc,v 1.14 2026/01/19 16:14:11 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/views/frame/system_menu_model_delegate.cc.orig	2026-01-07 00:50:30.000000000 +0000
+++ chrome/browser/ui/views/frame/system_menu_model_delegate.cc
@@ -24,7 +24,7 @@
 #include "chromeos/ui/frame/desks/move_to_desks_menu_model.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/common/pref_names.h"
 #endif
 
@@ -41,7 +41,7 @@ SystemMenuModelDelegate::SystemMenuModel
 SystemMenuModelDelegate::~SystemMenuModelDelegate() = default;
 
 bool SystemMenuModelDelegate::IsCommandIdChecked(int command_id) const {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (command_id == IDC_USE_SYSTEM_TITLE_BAR) {
     PrefService* prefs = browser_->profile()->GetPrefs();
     return !prefs->GetBoolean(prefs::kUseCustomChromeFrame);
@@ -67,7 +67,7 @@ bool SystemMenuModelDelegate::IsCommandI
 }
 
 bool SystemMenuModelDelegate::IsCommandIdVisible(int command_id) const {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   bool is_maximized = browser_->window()->IsMaximized();
   switch (command_id) {
     case IDC_MAXIMIZE_WINDOW:
