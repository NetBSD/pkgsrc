$NetBSD: patch-chrome_browser_ui_views_frame_browser__frame__view__factory__views.cc,v 1.17 2026/09/02 13:13:25 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/views/frame/browser_frame_view_factory_views.cc.orig	2026-08-31 22:47:51.000000000 +0000
+++ chrome/browser/ui/views/frame/browser_frame_view_factory_views.cc
@@ -16,7 +16,7 @@
 #include "chrome/browser/ui/views/frame/picture_in_picture_browser_frame_view.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/ui/views/frame/browser_frame_view_layout_linux.h"
 #include "chrome/browser/ui/views/frame/browser_frame_view_layout_linux_native.h"
 #include "chrome/browser/ui/views/frame/browser_frame_view_linux.h"
@@ -31,7 +31,7 @@ namespace chrome {
 
 namespace {
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 std::unique_ptr<OpaqueBrowserFrameView> CreateOpaqueBrowserFrameViewLinux(
     BrowserWidget* widget,
     BrowserView* browser_view) {
