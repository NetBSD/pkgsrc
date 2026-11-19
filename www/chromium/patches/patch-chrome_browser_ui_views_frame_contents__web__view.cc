$NetBSD: patch-chrome_browser_ui_views_frame_contents__web__view.cc,v 1.12 2026/11/19 19:45:55 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/views/frame/contents_web_view.cc.orig	2026-11-11 21:01:38.000000000 +0000
+++ chrome/browser/ui/views/frame/contents_web_view.cc
@@ -29,7 +29,7 @@
 #include "ui/wm/core/window_util.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/actor/actor_util.h"  // nogncheck
 #endif
 
@@ -181,7 +181,7 @@ void ContentsWebView::SetWebContents(con
       .Then(&web_modal::WebContentsModalDialogManager::UpdateDialogHost);
 }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 void ContentsWebView::DidGetUserInteraction(const blink::WebInputEvent& event) {
   // If the user interacts with the web contents, ensure it is activated.
   // This handles cases where the native window does not receive a focus
