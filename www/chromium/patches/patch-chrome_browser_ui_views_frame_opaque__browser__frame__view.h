$NetBSD: patch-chrome_browser_ui_views_frame_opaque__browser__frame__view.h,v 1.4 2025/07/25 16:17:13 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/views/frame/opaque_browser_frame_view.h.orig	2025-07-21 19:32:31.000000000 +0000
+++ chrome/browser/ui/views/frame/opaque_browser_frame_view.h
@@ -110,7 +110,7 @@ class OpaqueBrowserFrameView : public Br
   FrameButtonStyle GetFrameButtonStyle() const override;
   void UpdateWindowControlsOverlay(const gfx::Rect& bounding_rect) override;
   bool ShouldDrawRestoredFrameShadow() const override;
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   bool IsTiled() const override;
 #endif
   int WebAppButtonHeight() const override;
@@ -227,7 +227,7 @@ class OpaqueBrowserFrameView : public Br
   // Background painter for the window frame.
   std::unique_ptr<views::FrameBackground> frame_background_;
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   std::unique_ptr<views::MenuRunner> menu_runner_;
 #endif
 
