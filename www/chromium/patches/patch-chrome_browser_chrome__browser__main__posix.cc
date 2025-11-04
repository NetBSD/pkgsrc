$NetBSD: patch-chrome_browser_chrome__browser__main__posix.cc,v 1.9 2025/11/04 14:55:31 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/chrome_browser_main_posix.cc.orig	2025-10-24 16:42:30.000000000 +0000
+++ chrome/browser/chrome_browser_main_posix.cc
@@ -77,7 +77,7 @@ void ExitHandler::ExitWhenPossibleOnUITh
     // ExitHandler takes care of deleting itself.
     new ExitHandler();
   } else {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     switch (signal) {
       case SIGINT:
       case SIGHUP:
