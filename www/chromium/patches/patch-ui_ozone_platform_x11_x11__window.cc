$NetBSD: patch-ui_ozone_platform_x11_x11__window.cc,v 1.15 2026/02/15 09:04:14 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- ui/ozone/platform/x11/x11_window.cc.orig	2026-02-03 22:07:10.000000000 +0000
+++ ui/ozone/platform/x11/x11_window.cc
@@ -1505,7 +1505,7 @@ void X11Window::OnXWindowStateChanged() 
   WindowTiledEdges tiled_state = GetTiledState();
   if (tiled_state != tiled_state_) {
     tiled_state_ = tiled_state;
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     platform_window_delegate_->OnWindowTiledStateChanged(tiled_state);
     UpdateDecorationInsets();
 #endif
