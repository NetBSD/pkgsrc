$NetBSD: patch-chrome_browser_chrome__browser__main__extra__parts__ozone.cc,v 1.15 2026/02/15 09:03:57 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/chrome_browser_main_extra_parts_ozone.cc.orig	2026-02-03 22:07:10.000000000 +0000
+++ chrome/browser/chrome_browser_main_extra_parts_ozone.cc
@@ -28,7 +28,7 @@ void ChromeBrowserMainExtraPartsOzone::P
 }
 
 void ChromeBrowserMainExtraPartsOzone::PostMainMessageLoopRun() {
-#if !BUILDFLAG(IS_LINUX)
+#if !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_BSD)
   ui::OzonePlatform::GetInstance()->PostMainMessageLoopRun();
 #endif
 }
