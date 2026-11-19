$NetBSD: patch-chrome_browser_ui_views_frame_contents__web__view.h,v 1.12 2026/11/19 19:45:55 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/views/frame/contents_web_view.h.orig	2026-11-11 21:01:38.000000000 +0000
+++ chrome/browser/ui/views/frame/contents_web_view.h
@@ -63,7 +63,7 @@ class ContentsWebView : public views::We
   // This allows the browser to force focus synchronization in split view even
   // when native OS focus gets stuck on a different window (like a permission
   // prompt).
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   void DidGetUserInteraction(const blink::WebInputEvent& event) override;
 #endif
 
