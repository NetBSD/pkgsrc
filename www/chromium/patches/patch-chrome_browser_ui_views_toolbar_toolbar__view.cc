$NetBSD: patch-chrome_browser_ui_views_toolbar_toolbar__view.cc,v 1.2 2026/04/21 15:21:11 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/views/toolbar/toolbar_view.cc.orig	2026-04-14 23:31:37.000000000 +0200
+++ chrome/browser/ui/views/toolbar/toolbar_view.cc
@@ -457,7 +457,7 @@ void ToolbarView::Init() {
   }
 
   std::unique_ptr<MediaToolbarButtonView> media_button;
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   media_button = std::make_unique<MediaToolbarButtonView>(
       browser_view_,
       std::make_unique<MediaToolbarButtonContextualMenu>(browser_));
