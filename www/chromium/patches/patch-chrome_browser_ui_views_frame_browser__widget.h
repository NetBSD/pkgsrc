$NetBSD: patch-chrome_browser_ui_views_frame_browser__widget.h,v 1.7 2026/02/15 09:04:00 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/views/frame/browser_widget.h.orig	2026-02-03 22:07:10.000000000 +0000
+++ chrome/browser/ui/views/frame/browser_widget.h
@@ -65,7 +65,7 @@ class BrowserWidget : public views::Widg
 
   ~BrowserWidget() override;
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Returns whether the frame is in a tiled state.
   bool tiled() const { return tiled_; }
   void set_tiled(bool tiled) { tiled_ = tiled; }
@@ -187,7 +187,7 @@ class BrowserWidget : public views::Widg
   // contents for smoother dragging.
   TabDragKind tab_drag_kind_ = TabDragKind::kNone;
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   bool tiled_ = false;
 #endif
 };
