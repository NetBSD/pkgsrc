$NetBSD: patch-ui_views_widget_widget.cc,v 1.23 2026/07/08 13:42:34 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- ui/views/widget/widget.cc.orig	2026-07-06 22:58:46.000000000 +0000
+++ ui/views/widget/widget.cc
@@ -67,7 +67,7 @@
 #include "ui/views/window/dialog_delegate.h"
 #include "ui/wm/core/window_properties.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "ui/linux/linux_ui.h"
 #endif
 
@@ -2640,7 +2640,7 @@ const ui::NativeTheme* Widget::GetNative
     return parent_->GetNativeTheme();
   }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (auto* linux_ui_theme =
           ui::LinuxUiTheme::GetForWindow(GetNativeWindow())) {
     return linux_ui_theme->GetNativeTheme();
