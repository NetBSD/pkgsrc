$NetBSD: patch-content_browser_renderer__host_navigation__transitions_navigation__entry__screenshot.cc,v 1.11 2026/05/10 15:29:57 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- content/browser/renderer_host/navigation_transitions/navigation_entry_screenshot.cc.orig	2026-04-28 23:05:57.000000000 +0200
+++ content/browser/renderer_host/navigation_transitions/navigation_entry_screenshot.cc
@@ -71,7 +71,7 @@ void CompressNavigationScreenshotOnWorke
 }
 
 void AdviseBitmap(SkBitmap& bitmap) {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   size_t size = bitmap.info().computeByteSize(bitmap.info().minRowBytes());
   if (madvise(bitmap.getPixels(), size, MADV_POPULATE_WRITE) == 0) {
     return;
