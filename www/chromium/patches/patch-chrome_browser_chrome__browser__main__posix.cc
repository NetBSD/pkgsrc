$NetBSD: patch-chrome_browser_chrome__browser__main__posix.cc,v 1.15 2026/02/15 09:03:57 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/chrome_browser_main_posix.cc.orig	2026-02-03 22:07:10.000000000 +0000
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
