$NetBSD: patch-chrome_browser_chrome__browser__main__posix.cc,v 1.19 2026/05/10 15:29:49 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/chrome_browser_main_posix.cc.orig	2026-04-28 23:05:57.000000000 +0200
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
