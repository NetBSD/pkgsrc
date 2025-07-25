$NetBSD: patch-chrome_browser_chrome__browser__main__posix.cc,v 1.4 2025/07/25 16:17:10 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/chrome_browser_main_posix.cc.orig	2025-07-21 19:32:31.000000000 +0000
+++ chrome/browser/chrome_browser_main_posix.cc
@@ -81,7 +81,7 @@ void ExitHandler::ExitWhenPossibleOnUITh
     // ExitHandler takes care of deleting itself.
     new ExitHandler();
   } else {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     switch (signal) {
       case SIGINT:
       case SIGHUP:
