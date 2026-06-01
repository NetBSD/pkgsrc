$NetBSD: patch-chrome_browser_ui_views_profiles_profile__picker__view.cc,v 1.20 2026/06/01 10:09:09 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/views/profiles/profile_picker_view.cc.orig	2026-05-26 20:39:02.000000000 +0000
+++ chrome/browser/ui/views/profiles/profile_picker_view.cc
@@ -88,7 +88,7 @@
 #include "chrome/browser/global_keyboard_shortcuts_mac.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/shell_integration_linux.h"
 #endif
 
@@ -113,7 +113,7 @@ class ProfilePickerWidget : public views
     views::Widget::InitParams params(
         views::Widget::InitParams::NATIVE_WIDGET_OWNS_WIDGET);
     params.delegate = profile_picker_view;
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     params.wm_class_name = shell_integration_linux::GetProgramClassName();
     params.wm_class_class = shell_integration_linux::GetProgramClassClass();
     params.wayland_app_id = params.wm_class_class;
