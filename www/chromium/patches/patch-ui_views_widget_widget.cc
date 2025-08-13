$NetBSD: patch-ui_views_widget_widget.cc,v 1.5 2025/08/13 07:44:35 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- ui/views/widget/widget.cc.orig	2025-07-29 22:51:44.000000000 +0000
+++ ui/views/widget/widget.cc
@@ -63,7 +63,7 @@
 #include "ui/views/widget/widget_removals_observer.h"
 #include "ui/views/window/dialog_delegate.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "ui/linux/linux_ui.h"
 #endif
 
@@ -2493,7 +2493,7 @@ const ui::NativeTheme* Widget::GetNative
     return parent_->GetNativeTheme();
   }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (auto* linux_ui_theme =
           ui::LinuxUiTheme::GetForWindow(GetNativeWindow())) {
     return linux_ui_theme->GetNativeTheme();
