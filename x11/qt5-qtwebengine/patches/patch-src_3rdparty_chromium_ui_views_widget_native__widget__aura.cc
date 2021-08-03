$NetBSD: patch-src_3rdparty_chromium_ui_views_widget_native__widget__aura.cc,v 1.1 2021/08/03 21:04:36 markd Exp $

--- src/3rdparty/chromium/ui/views/widget/native_widget_aura.cc.orig	2020-11-07 01:22:36.000000000 +0000
+++ src/3rdparty/chromium/ui/views/widget/native_widget_aura.cc
@@ -64,7 +64,7 @@
 #include "ui/views/widget/desktop_aura/desktop_window_tree_host_win.h"
 #endif
 
-#if BUILDFLAG(ENABLE_DESKTOP_AURA) && defined(OS_LINUX)
+#if BUILDFLAG(ENABLE_DESKTOP_AURA) && (defined(OS_LINUX) || defined(OS_BSD))
 #include "ui/views/linux_ui/linux_ui.h"
 #include "ui/views/widget/desktop_aura/desktop_window_tree_host_linux.h"
 #endif
@@ -1102,13 +1102,13 @@ void Widget::CloseAllSecondaryWidgets() 
   EnumThreadWindows(GetCurrentThreadId(), WindowCallbackProc, 0);
 #endif
 
-#if BUILDFLAG(ENABLE_DESKTOP_AURA) && defined(OS_LINUX)
+#if BUILDFLAG(ENABLE_DESKTOP_AURA) && (defined(OS_LINUX) || defined(OS_BSD))
   DesktopWindowTreeHostLinux::CleanUpWindowList(CloseWindow);
 #endif
 }
 
 const ui::NativeTheme* Widget::GetNativeTheme() const {
-#if BUILDFLAG(ENABLE_DESKTOP_AURA) && defined(OS_LINUX)
+#if BUILDFLAG(ENABLE_DESKTOP_AURA) && (defined(OS_LINUX) || defined(OS_BSD))
   const LinuxUI* linux_ui = LinuxUI::instance();
   if (linux_ui) {
     ui::NativeTheme* native_theme =
