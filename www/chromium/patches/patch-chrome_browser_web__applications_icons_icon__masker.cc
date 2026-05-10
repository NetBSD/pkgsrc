$NetBSD: patch-chrome_browser_web__applications_icons_icon__masker.cc,v 1.12 2026/05/10 15:29:53 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/web_applications/icons/icon_masker.cc.orig	2026-04-28 23:05:57.000000000 +0200
+++ chrome/browser/web_applications/icons/icon_masker.cc
@@ -12,7 +12,7 @@
 
 namespace web_app {
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 void MaskIconOnOs(SkBitmap input_bitmap, MaskedIconCallback masked_callback) {
   base::SequencedTaskRunner::GetCurrentDefault()->PostTask(
       FROM_HERE,
