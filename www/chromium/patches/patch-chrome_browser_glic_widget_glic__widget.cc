$NetBSD: patch-chrome_browser_glic_widget_glic__widget.cc,v 1.2 2025/09/08 13:24:18 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/glic/widget/glic_widget.cc.orig	2025-08-29 18:50:09.000000000 +0000
+++ chrome/browser/glic/widget/glic_widget.cc
@@ -127,7 +127,7 @@ std::unique_ptr<GlicWidget> GlicWidget::
   // Don't change this name. This is used by other code to identify the glic
   // window. See b/404947780.
   params.name = "GlicWidget";
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   params.wm_class_class = shell_integration_linux::GetProgramClassClass();
   params.wayland_app_id = params.wm_class_class + "-glic";
 #endif
