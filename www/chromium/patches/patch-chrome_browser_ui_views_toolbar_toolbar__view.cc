$NetBSD: patch-chrome_browser_ui_views_toolbar_toolbar__view.cc,v 1.9 2026/09/02 13:13:26 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/views/toolbar/toolbar_view.cc.orig	2026-08-31 22:47:51.000000000 +0000
+++ chrome/browser/ui/views/toolbar/toolbar_view.cc
@@ -395,7 +395,7 @@ void ToolbarView::Init() {
   }
 
   std::unique_ptr<MediaToolbarButtonView> media_button;
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (!features::IsWebUIMediaButtonEnabled()) {
     media_button = std::make_unique<MediaToolbarButtonView>(
         browser_view_,
