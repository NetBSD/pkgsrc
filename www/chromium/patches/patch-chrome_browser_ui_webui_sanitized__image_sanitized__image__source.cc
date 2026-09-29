$NetBSD: patch-chrome_browser_ui_webui_sanitized__image_sanitized__image__source.cc,v 1.9 2026/09/29 07:42:52 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/webui/sanitized_image/sanitized_image_source.cc.orig	2026-09-22 00:09:16.000000000 +0000
+++ chrome/browser/ui/webui/sanitized_image/sanitized_image_source.cc
@@ -350,7 +350,7 @@ void SanitizedImageSource::OnAnimationDe
   }
 
 #if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_LINUX)
+    BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (mojo_frames.size() > 1) {
     // The image is animated, re-encode as WebP animated image and send to
     // requester.
