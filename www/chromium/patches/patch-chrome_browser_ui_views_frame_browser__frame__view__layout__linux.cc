$NetBSD: patch-chrome_browser_ui_views_frame_browser__frame__view__layout__linux.cc,v 1.1 2025/02/06 09:57:53 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/views/frame/browser_frame_view_layout_linux.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ chrome/browser/ui/views/frame/browser_frame_view_layout_linux.cc
@@ -54,7 +54,7 @@ gfx::Insets BrowserFrameViewLayoutLinux:
         OpaqueBrowserFrameViewLayout::RestoredFrameBorderInsets());
   }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   const bool tiled = delegate_->IsTiled();
 #else
   const bool tiled = false;
