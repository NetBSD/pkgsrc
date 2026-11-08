$NetBSD: patch-chrome_browser_ui_views_frame_browser__view.cc,v 1.32 2026/11/08 15:38:56 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/views/frame/browser_view.cc.orig	2026-11-02 23:22:33.000000000 +0000
+++ chrome/browser/ui/views/frame/browser_view.cc
@@ -2472,7 +2472,7 @@ void BrowserView::ToolbarSizeChanged(boo
 }
 
 void BrowserView::TabDraggingStatusChanged(bool is_dragging) {
-#if !BUILDFLAG(IS_LINUX)
+#if !BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   UpdateFastResizeForContentViews(is_dragging);
 
   if (!is_dragging) {
