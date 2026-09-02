$NetBSD: patch-chrome_browser_ui_views_frame_contents__web__view.h,v 1.4 2026/09/02 13:13:25 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/views/frame/contents_web_view.h.orig	2026-08-31 22:47:51.000000000 +0000
+++ chrome/browser/ui/views/frame/contents_web_view.h
@@ -68,7 +68,7 @@ class ContentsWebView : public views::We
   // This allows the browser to force focus synchronization in split view even
   // when native OS focus gets stuck on a different window (like a permission
   // prompt).
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   void DidGetUserInteraction(const blink::WebInputEvent& event) override;
 #endif
 
