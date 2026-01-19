$NetBSD: patch-chrome_browser_ui_views_apps_chrome__native__app__window__views__aura.cc,v 1.14 2026/01/19 16:14:10 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/views/apps/chrome_native_app_window_views_aura.cc.orig	2026-01-07 00:50:30.000000000 +0000
+++ chrome/browser/ui/views/apps/chrome_native_app_window_views_aura.cc
@@ -19,7 +19,7 @@
 #include "ui/menus/simple_menu_model.h"
 #include "ui/views/widget/widget.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/shell_integration_linux.h"
 #endif
 
@@ -49,7 +49,7 @@ void ChromeNativeAppWindowViewsAura::OnB
     const AppWindow::CreateParams& create_params,
     views::Widget::InitParams* init_params,
     views::Widget* widget) {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   std::string app_name =
       web_app::GenerateApplicationNameFromAppId(app_window()->extension_id());
   // Set up a custom WM_CLASS for app windows. This allows task switchers in
