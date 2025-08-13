$NetBSD: patch-chrome_browser_chrome__browser__main__extra__parts__linux.cc,v 1.5 2025/08/13 07:44:17 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/chrome_browser_main_extra_parts_linux.cc.orig	2025-07-29 22:51:44.000000000 +0000
+++ chrome/browser/chrome_browser_main_extra_parts_linux.cc
@@ -60,7 +60,7 @@ void ChromeBrowserMainExtraPartsLinux::P
 
 // static
 void ChromeBrowserMainExtraPartsLinux::InitOzonePlatformHint() {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   base::CommandLine* const command_line =
       base::CommandLine::ForCurrentProcess();
   std::unique_ptr<base::Environment> env = base::Environment::Create();
