$NetBSD: patch-chrome_browser_ui_views_frame_picture__in__picture__browser__frame__view.cc,v 1.4 2025/07/25 16:17:13 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/views/frame/picture_in_picture_browser_frame_view.cc.orig	2025-07-21 19:32:31.000000000 +0000
+++ chrome/browser/ui/views/frame/picture_in_picture_browser_frame_view.cc
@@ -67,7 +67,7 @@
 
 // Windows, Mac and CrOS do not clip child widgets to their parents, so we
 // don't have to worry about resizing quite as much.
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #define PLATFORM_CLIPS_CHILD_WINDOWS
 #endif
 
