$NetBSD: patch-apps_ui_views_app__window__frame__view.cc,v 1.7 2025/09/12 16:02:18 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- apps/ui/views/app_window_frame_view.cc.orig	2025-09-08 23:21:33.000000000 +0000
+++ apps/ui/views/app_window_frame_view.cc
@@ -146,7 +146,7 @@ gfx::Rect AppWindowFrameView::GetBoundsF
 gfx::Rect AppWindowFrameView::GetWindowBoundsForClientBounds(
     const gfx::Rect& client_bounds) const {
   gfx::Rect window_bounds = client_bounds;
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Get the difference between the widget's client area bounds and window
   // bounds, and grow |window_bounds| by that amount.
   gfx::Insets native_frame_insets =
