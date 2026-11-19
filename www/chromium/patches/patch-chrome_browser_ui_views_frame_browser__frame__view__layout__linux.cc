$NetBSD: patch-chrome_browser_ui_views_frame_browser__frame__view__layout__linux.cc,v 1.33 2026/11/19 19:45:55 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/views/frame/browser_frame_view_layout_linux.cc.orig	2026-11-11 21:01:38.000000000 +0000
+++ chrome/browser/ui/views/frame/browser_frame_view_layout_linux.cc
@@ -52,7 +52,7 @@ gfx::Insets BrowserFrameViewLayoutLinux:
         OpaqueBrowserFrameViewLayout::RestoredFrameBorderInsets());
   }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   const bool tiled = delegate_->IsTiled();
 #else
   const bool tiled = false;
