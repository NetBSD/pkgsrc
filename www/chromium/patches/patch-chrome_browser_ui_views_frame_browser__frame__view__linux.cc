$NetBSD: patch-chrome_browser_ui_views_frame_browser__frame__view__linux.cc,v 1.4 2025/07/25 16:17:12 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/views/frame/browser_frame_view_linux.cc.orig	2025-07-21 19:32:31.000000000 +0000
+++ chrome/browser/ui/views/frame/browser_frame_view_linux.cc
@@ -70,7 +70,7 @@ gfx::ShadowValues BrowserFrameViewLinux:
 
 void BrowserFrameViewLinux::PaintRestoredFrameBorder(
     gfx::Canvas* canvas) const {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   const bool tiled = frame()->tiled();
 #else
   const bool tiled = false;
@@ -125,7 +125,7 @@ int BrowserFrameViewLinux::NonClientHitT
 }
 
 float BrowserFrameViewLinux::GetRestoredCornerRadiusDip() const {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   const bool tiled = frame()->tiled();
 #else
   const bool tiled = false;
