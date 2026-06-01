$NetBSD: patch-apps_ui_views_app__window__frame__view.cc,v 1.20 2026/06/01 10:09:03 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- apps/ui/views/app_window_frame_view.cc.orig	2026-05-26 20:39:02.000000000 +0000
+++ apps/ui/views/app_window_frame_view.cc
@@ -147,7 +147,7 @@ gfx::Rect AppWindowFrameView::GetBoundsF
 gfx::Rect AppWindowFrameView::GetWindowBoundsForClientBounds(
     const gfx::Rect& client_bounds) const {
   gfx::Rect window_bounds = client_bounds;
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Get the difference between the widget's client area bounds and window
   // bounds, and grow |window_bounds| by that amount.
   gfx::Insets native_frame_insets =
