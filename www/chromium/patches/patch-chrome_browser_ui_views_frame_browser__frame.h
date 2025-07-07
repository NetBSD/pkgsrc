$NetBSD: patch-chrome_browser_ui_views_frame_browser__frame.h,v 1.3 2025/07/07 09:23:28 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/views/frame/browser_frame.h.orig	2025-06-30 06:54:11.000000000 +0000
+++ chrome/browser/ui/views/frame/browser_frame.h
@@ -66,7 +66,7 @@ class BrowserFrame : public views::Widge
 
   ~BrowserFrame() override;
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Returns whether the frame is in a tiled state.
   bool tiled() const { return tiled_; }
   void set_tiled(bool tiled) { tiled_ = tiled; }
@@ -227,7 +227,7 @@ class BrowserFrame : public views::Widge
   // contents for smoother dragging.
   TabDragKind tab_drag_kind_ = TabDragKind::kNone;
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   bool tiled_ = false;
 #endif
 
