$NetBSD: patch-chrome_browser_ui_views_apps_chrome__native__app__window__views__aura.cc,v 1.24 2026/08/09 06:31:11 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/views/apps/chrome_native_app_window_views_aura.cc.orig	2026-08-05 20:17:42.000000000 +0000
+++ chrome/browser/ui/views/apps/chrome_native_app_window_views_aura.cc
@@ -17,7 +17,7 @@
 #include "ui/base/mojom/window_show_state.mojom.h"
 #include "ui/views/widget/widget.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/shell_integration_linux.h"
 #endif
 
@@ -47,7 +47,7 @@ void ChromeNativeAppWindowViewsAura::OnB
     const AppWindow::CreateParams& create_params,
     views::Widget::InitParams* init_params,
     views::Widget* widget) {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   std::string app_name =
       web_app::GenerateApplicationNameFromAppId(app_window()->extension_id());
   // Set up a custom WM_CLASS for app windows. This allows task switchers in
