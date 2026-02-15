$NetBSD: patch-chrome_browser_glic_widget_glic__widget.cc,v 1.11 2026/02/15 09:03:58 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/glic/widget/glic_widget.cc.orig	2026-02-03 22:07:10.000000000 +0000
+++ chrome/browser/glic/widget/glic_widget.cc
@@ -51,7 +51,7 @@
 #include "ui/views/win/hwnd_util.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/shell_integration_linux.h"
 #endif
 
@@ -391,7 +391,7 @@ std::unique_ptr<GlicWidget> GlicWidget::
 #if BUILDFLAG(IS_MAC)
   params.animation_enabled = true;
 #endif  // BUILDFLAG(IS_MAC)
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   params.wm_class_class = shell_integration_linux::GetProgramClassClass();
   params.wayland_app_id = params.wm_class_class + "-glic";
 #endif  // BUILDFLAG(IS_LINUX)
