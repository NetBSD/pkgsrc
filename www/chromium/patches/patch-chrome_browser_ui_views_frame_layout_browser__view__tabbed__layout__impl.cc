$NetBSD: patch-chrome_browser_ui_views_frame_layout_browser__view__tabbed__layout__impl.cc,v 1.3 2026/07/08 13:42:18 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/views/frame/layout/browser_view_tabbed_layout_impl.cc.orig	2026-07-06 22:58:46.000000000 +0000
+++ chrome/browser/ui/views/frame/layout/browser_view_tabbed_layout_impl.cc
@@ -250,7 +250,7 @@ int BrowserViewTabbedLayoutImpl::GetHori
 }
 
 bool BrowserViewTabbedLayoutImpl::AvoidCrackingForFractionalDisplay() const {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   // This is primarily an issue on Linux and Windows; add other platforms here
   // as needed.
   if (auto* const widget = views().browser_view->GetWidget()) {
