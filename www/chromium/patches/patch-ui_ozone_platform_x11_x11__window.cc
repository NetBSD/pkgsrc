$NetBSD: patch-ui_ozone_platform_x11_x11__window.cc,v 1.1 2025/02/06 09:58:34 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- ui/ozone/platform/x11/x11_window.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ ui/ozone/platform/x11/x11_window.cc
@@ -1504,7 +1504,7 @@ void X11Window::OnXWindowStateChanged() 
   WindowTiledEdges tiled_state = GetTiledState();
   if (tiled_state != tiled_state_) {
     tiled_state_ = tiled_state;
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     platform_window_delegate_->OnWindowTiledStateChanged(tiled_state);
     UpdateDecorationInsets();
 #endif
