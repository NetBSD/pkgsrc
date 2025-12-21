$NetBSD: patch-src_3rdparty_chromium_ui_views_window_custom__frame__view.cc,v 1.1 2025/12/21 09:38:50 markd Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/ui/views/window/custom_frame_view.cc.orig	2025-10-02 00:36:39.000000000 +0000
+++ src/3rdparty/chromium/ui/views/window/custom_frame_view.cc
@@ -279,7 +279,7 @@ int CustomFrameView::NonClientTopBorderH
 int CustomFrameView::CaptionButtonY() const {
   // Maximized buttons start at window top so that even if their images aren't
   // drawn flush with the screen edge, they still obey Fitts' Law.
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return FrameBorderThickness();
 #else
   return frame_->IsMaximized() ? FrameBorderThickness() : kFrameShadowThickness;
