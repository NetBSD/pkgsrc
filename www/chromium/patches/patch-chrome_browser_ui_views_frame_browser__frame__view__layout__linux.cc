$NetBSD: patch-chrome_browser_ui_views_frame_browser__frame__view__layout__linux.cc,v 1.19 2026/05/10 15:29:52 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/views/frame/browser_frame_view_layout_linux.cc.orig	2026-04-28 23:05:57.000000000 +0200
+++ chrome/browser/ui/views/frame/browser_frame_view_layout_linux.cc
@@ -55,7 +55,7 @@ gfx::Insets BrowserFrameViewLayoutLinux:
         OpaqueBrowserFrameViewLayout::RestoredFrameBorderInsets());
   }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   const bool tiled = delegate_->IsTiled();
 #else
   const bool tiled = false;
