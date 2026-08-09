$NetBSD: patch-ui_views_window_default__frame__view.cc,v 1.20 2026/08/09 06:31:26 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- ui/views/window/default_frame_view.cc.orig	2026-08-05 20:17:42.000000000 +0000
+++ ui/views/window/default_frame_view.cc
@@ -285,7 +285,7 @@ int DefaultFrameView::NonClientTopBorder
 int DefaultFrameView::CaptionButtonY() const {
   // Maximized buttons start at window top so that even if their images aren't
   // drawn flush with the screen edge, they still obey Fitts' Law.
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return FrameBorderThickness();
 #else
   return widget_->IsMaximized() ? FrameBorderThickness()
