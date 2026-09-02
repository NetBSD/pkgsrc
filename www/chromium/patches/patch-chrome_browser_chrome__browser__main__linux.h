$NetBSD: patch-chrome_browser_chrome__browser__main__linux.h,v 1.25 2026/09/02 13:13:22 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/chrome_browser_main_linux.h.orig	2026-08-31 22:47:51.000000000 +0000
+++ chrome/browser/chrome_browser_main_linux.h
@@ -31,7 +31,7 @@ class ChromeBrowserMainPartsLinux : publ
 
   // ChromeBrowserMainPartsPosix overrides.
   void PostCreateMainMessageLoop() override;
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   void PostMainMessageLoopRun() override;
 #endif
   void PreProfileInit() override;
