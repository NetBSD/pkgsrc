$NetBSD: patch-ui_views_window_default__frame__view.cc,v 1.2 2025/09/08 13:24:35 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- ui/views/window/default_frame_view.cc.orig	2025-08-29 18:50:09.000000000 +0000
+++ ui/views/window/default_frame_view.cc
@@ -285,7 +285,7 @@ int DefaultFrameView::NonClientTopBorder
 int DefaultFrameView::CaptionButtonY() const {
   // Maximized buttons start at window top so that even if their images aren't
   // drawn flush with the screen edge, they still obey Fitts' Law.
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return FrameBorderThickness();
 #else
   return frame_->IsMaximized() ? FrameBorderThickness() : kFrameShadowThickness;
