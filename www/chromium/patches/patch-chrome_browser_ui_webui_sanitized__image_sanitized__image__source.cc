$NetBSD: patch-chrome_browser_ui_webui_sanitized__image_sanitized__image__source.cc,v 1.1 2026/05/10 15:29:53 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/webui/sanitized_image/sanitized_image_source.cc.orig	2026-04-28 23:05:57.000000000 +0200
+++ chrome/browser/ui/webui/sanitized_image/sanitized_image_source.cc
@@ -320,7 +320,7 @@ void SanitizedImageSource::OnAnimationDe
   }
 
 #if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_LINUX)
+    BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (mojo_frames.size() > 1) {
     // The image is animated, re-encode as WebP animated image and send to
     // requester.
