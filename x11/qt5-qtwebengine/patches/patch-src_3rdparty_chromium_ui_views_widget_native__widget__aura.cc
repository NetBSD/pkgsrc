$NetBSD: patch-src_3rdparty_chromium_ui_views_widget_native__widget__aura.cc,v 1.2 2022/04/18 11:18:19 adam Exp $

--- src/3rdparty/chromium/ui/views/widget/native_widget_aura.cc.orig	2021-02-19 16:41:59.000000000 +0000
+++ src/3rdparty/chromium/ui/views/widget/native_widget_aura.cc
@@ -65,7 +65,7 @@
 #endif
 
 #if BUILDFLAG(ENABLE_DESKTOP_AURA) && \
-    (defined(OS_LINUX) || defined(OS_CHROMEOS))
+    (defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD))
 #include "ui/views/linux_ui/linux_ui.h"
 #include "ui/views/widget/desktop_aura/desktop_window_tree_host_linux.h"
 #endif
@@ -1106,14 +1106,14 @@ void Widget::CloseAllSecondaryWidgets() 
 #endif
 
 #if BUILDFLAG(ENABLE_DESKTOP_AURA) && \
-    (defined(OS_LINUX) || defined(OS_CHROMEOS))
+    (defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD))
   DesktopWindowTreeHostLinux::CleanUpWindowList(CloseWindow);
 #endif
 }
 
 const ui::NativeTheme* Widget::GetNativeTheme() const {
 #if BUILDFLAG(ENABLE_DESKTOP_AURA) && \
-    (defined(OS_LINUX) || defined(OS_CHROMEOS))
+    (defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD))
   const LinuxUI* linux_ui = LinuxUI::instance();
   if (linux_ui) {
     ui::NativeTheme* native_theme =
