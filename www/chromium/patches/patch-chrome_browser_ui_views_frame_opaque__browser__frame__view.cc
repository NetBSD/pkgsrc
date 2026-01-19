$NetBSD: patch-chrome_browser_ui_views_frame_opaque__browser__frame__view.cc,v 1.14 2026/01/19 16:14:11 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/views/frame/opaque_browser_frame_view.cc.orig	2026-01-07 00:50:30.000000000 +0000
+++ chrome/browser/ui/views/frame/opaque_browser_frame_view.cc
@@ -55,7 +55,7 @@
 #include "ui/views/window/vector_icons/vector_icons.h"
 #include "ui/views/window/window_shape.h"
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "ui/views/controls/menu/menu_runner.h"
 #endif
 
@@ -610,7 +610,7 @@ bool OpaqueBrowserFrameView::IsFrameCond
 
 OpaqueBrowserFrameView::FrameButtonStyle
 OpaqueBrowserFrameView::GetFrameButtonStyle() const {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return FrameButtonStyle::kMdButton;
 #else
   return FrameButtonStyle::kImageButton;
@@ -629,7 +629,7 @@ bool OpaqueBrowserFrameView::ShouldDrawR
   return false;
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 bool OpaqueBrowserFrameView::IsTiled() const {
   return browser_widget()->tiled();
 }
@@ -861,7 +861,7 @@ gfx::Rect OpaqueBrowserFrameView::GetIco
 }
 
 void OpaqueBrowserFrameView::WindowIconPressed() {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Chrome OS doesn't show the window icon, and Windows handles this on its own
   // due to the hit test being HTSYSMENU.
   menu_runner_ = std::make_unique<views::MenuRunner>(
