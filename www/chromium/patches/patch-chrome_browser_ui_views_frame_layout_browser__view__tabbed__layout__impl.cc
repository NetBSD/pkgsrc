$NetBSD: patch-chrome_browser_ui_views_frame_layout_browser__view__tabbed__layout__impl.cc,v 1.11 2026/10/23 15:05:21 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/views/frame/layout/browser_view_tabbed_layout_impl.cc.orig	2026-10-19 20:07:21.000000000 +0000
+++ chrome/browser/ui/views/frame/layout/browser_view_tabbed_layout_impl.cc
@@ -334,7 +334,7 @@ int BrowserViewTabbedLayoutImpl::GetHori
 }
 
 int BrowserViewTabbedLayoutImpl::GetVerticalTabStripContentOverlap() const {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   // On fractional display scaling (e.g. 1.25x, 1.5x), overlap the content area
   // by 1 DIP over the vertical tab strip border to prevent subpixel seams.
   if (auto* const widget = views().browser_view->GetWidget()) {
