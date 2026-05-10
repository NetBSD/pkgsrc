$NetBSD: patch-chrome_browser_ui_views_frame_browser__widget.h,v 1.11 2026/05/10 15:29:52 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/views/frame/browser_widget.h.orig	2026-04-28 23:05:57.000000000 +0200
+++ chrome/browser/ui/views/frame/browser_widget.h
@@ -66,7 +66,7 @@ class BrowserWidget : public views::Widg
 
   ~BrowserWidget() override;
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Returns whether the frame is in a tiled state.
   bool tiled() const { return tiled_; }
   void set_tiled(bool tiled) { tiled_ = tiled; }
@@ -193,7 +193,7 @@ class BrowserWidget : public views::Widg
   // contents for smoother dragging.
   TabDragKind tab_drag_kind_ = TabDragKind::kNone;
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   bool tiled_ = false;
 #endif
 };
