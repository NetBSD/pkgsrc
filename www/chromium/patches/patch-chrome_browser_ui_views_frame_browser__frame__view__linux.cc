$NetBSD: patch-chrome_browser_ui_views_frame_browser__frame__view__linux.cc,v 1.19 2026/05/10 15:29:52 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/views/frame/browser_frame_view_linux.cc.orig	2026-04-28 23:05:57.000000000 +0200
+++ chrome/browser/ui/views/frame/browser_frame_view_linux.cc
@@ -72,7 +72,7 @@ gfx::ShadowValues BrowserFrameViewLinux:
 
 void BrowserFrameViewLinux::PaintRestoredFrameBorder(
     gfx::Canvas* canvas) const {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   const bool tiled = browser_widget()->tiled();
 #else
   const bool tiled = false;
@@ -127,7 +127,7 @@ int BrowserFrameViewLinux::NonClientHitT
 }
 
 float BrowserFrameViewLinux::GetRestoredCornerRadiusDip() const {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   const bool tiled = browser_widget()->tiled();
 #else
   const bool tiled = false;
