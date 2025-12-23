$NetBSD: patch-ui_ozone_platform_x11_x11__window.cc,v 1.13 2025/12/23 13:22:27 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- ui/ozone/platform/x11/x11_window.cc.orig	2025-12-17 23:05:18.000000000 +0000
+++ ui/ozone/platform/x11/x11_window.cc
@@ -1503,7 +1503,7 @@ void X11Window::OnXWindowStateChanged() 
   WindowTiledEdges tiled_state = GetTiledState();
   if (tiled_state != tiled_state_) {
     tiled_state_ = tiled_state;
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     platform_window_delegate_->OnWindowTiledStateChanged(tiled_state);
     UpdateDecorationInsets();
 #endif
