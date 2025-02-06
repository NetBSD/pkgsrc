$NetBSD: patch-chrome_browser_chrome__browser__main__extra__parts__ozone.cc,v 1.1 2025/02/06 09:57:45 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/chrome_browser_main_extra_parts_ozone.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ chrome/browser/chrome_browser_main_extra_parts_ozone.cc
@@ -27,7 +27,7 @@ void ChromeBrowserMainExtraPartsOzone::P
 }
 
 void ChromeBrowserMainExtraPartsOzone::PostMainMessageLoopRun() {
-#if !BUILDFLAG(IS_CHROMEOS_LACROS) && !BUILDFLAG(IS_LINUX)
+#if !BUILDFLAG(IS_CHROMEOS_LACROS) && !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_BSD)
   // Lacros's `PostMainMessageLoopRun` must be called at the very end of
   // `PostMainMessageLoopRun` in
   // `ChromeBrowserMainPartsLacros::PostMainMessageLoopRun`.
