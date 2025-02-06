$NetBSD: patch-ui_views_widget_desktop__aura_desktop__window__tree__host__platform__impl__interactive__uitest.cc,v 1.1 2025/02/06 09:58:35 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- ui/views/widget/desktop_aura/desktop_window_tree_host_platform_impl_interactive_uitest.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ ui/views/widget/desktop_aura/desktop_window_tree_host_platform_impl_interactive_uitest.cc
@@ -23,7 +23,7 @@
 #include "ui/views/widget/widget_delegate.h"
 #include "ui/views/window/native_frame_view.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "ui/views/widget/desktop_aura/desktop_window_tree_host_linux.h"
 #include "ui/views/widget/desktop_aura/window_event_filter_linux.h"
 using DesktopWindowTreeHostPlatformImpl = views::DesktopWindowTreeHostLinux;
