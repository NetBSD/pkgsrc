$NetBSD: patch-chrome_browser_ui_views_frame_contents__web__view.cc,v 1.3 2026/08/09 06:31:11 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/views/frame/contents_web_view.cc.orig	2026-08-05 20:17:42.000000000 +0000
+++ chrome/browser/ui/views/frame/contents_web_view.cc
@@ -171,7 +171,7 @@ void ContentsWebView::SetWebContents(con
   }
 }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 void ContentsWebView::DidGetUserInteraction(const blink::WebInputEvent& event) {
   // If the user interacts with the web contents, ensure it is activated.
   // This handles cases where the native window does not receive a focus
