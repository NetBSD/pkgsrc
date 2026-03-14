$NetBSD: patch-chrome_browser_ui_views_frame_multi__contents__view__drop__target__controller.h,v 1.1 2026/03/14 12:40:28 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/views/frame/multi_contents_view_drop_target_controller.h.orig	2026-03-11 22:12:25.000000000 +0000
+++ chrome/browser/ui/views/frame/multi_contents_view_drop_target_controller.h
@@ -32,7 +32,7 @@ class MultiContentsViewDropTargetControl
       public MultiContentsDropTargetView::DragDelegate {
  public:
   static constexpr base::TimeDelta kShowDropTargetForTabDelay =
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       base::Milliseconds(1000);
 #else
       base::Milliseconds(500);
