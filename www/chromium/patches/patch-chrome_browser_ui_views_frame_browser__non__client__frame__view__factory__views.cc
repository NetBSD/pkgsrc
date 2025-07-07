$NetBSD: patch-chrome_browser_ui_views_frame_browser__non__client__frame__view__factory__views.cc,v 1.3 2025/07/07 09:23:28 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/views/frame/browser_non_client_frame_view_factory_views.cc.orig	2025-06-30 06:54:11.000000000 +0000
+++ chrome/browser/ui/views/frame/browser_non_client_frame_view_factory_views.cc
@@ -15,7 +15,7 @@
 #include "chrome/browser/ui/views/frame/browser_frame_view_win.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/ui/views/frame/browser_frame_view_layout_linux.h"
 #include "chrome/browser/ui/views/frame/browser_frame_view_layout_linux_native.h"
 #include "chrome/browser/ui/views/frame/browser_frame_view_linux_native.h"
@@ -33,7 +33,7 @@ namespace {
 std::unique_ptr<OpaqueBrowserFrameView> CreateOpaqueBrowserFrameView(
     BrowserFrame* frame,
     BrowserView* browser_view) {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   auto* profile = browser_view->browser()->profile();
   auto* linux_ui_theme = ui::LinuxUiTheme::GetForProfile(profile);
   auto* theme_service_factory = ThemeServiceFactory::GetForProfile(profile);
@@ -83,7 +83,7 @@ std::unique_ptr<BrowserNonClientFrameVie
     BrowserFrame* frame,
     BrowserView* browser_view) {
   if (browser_view->browser()->is_type_picture_in_picture()) {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     return std::make_unique<PictureInPictureBrowserFrameViewLinux>(
         frame, browser_view);
 #else
