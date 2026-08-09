$NetBSD: patch-chrome_browser_ui_views_frame_browser__frame__view__layout__linux__native.cc,v 1.24 2026/08/09 06:31:11 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/views/frame/browser_frame_view_layout_linux_native.cc.orig	2026-08-05 20:17:42.000000000 +0000
+++ chrome/browser/ui/views/frame/browser_frame_view_layout_linux_native.cc
@@ -19,7 +19,7 @@ BrowserFrameViewLayoutLinuxNative::~Brow
 
 ui::WindowFrameProvider* BrowserFrameViewLayoutLinuxNative::GetFrameProvider()
     const {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   const bool tiled = delegate_->IsTiled();
   const bool maximized = delegate_->IsMaximized();
 #else
