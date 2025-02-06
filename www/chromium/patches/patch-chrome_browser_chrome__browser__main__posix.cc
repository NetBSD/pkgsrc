$NetBSD: patch-chrome_browser_chrome__browser__main__posix.cc,v 1.1 2025/02/06 09:57:45 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/chrome_browser_main_posix.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ chrome/browser/chrome_browser_main_posix.cc
@@ -79,7 +79,7 @@ void ExitHandler::ExitWhenPossibleOnUITh
   } else {
 // TODO(crbug.com/40118868): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
     switch (signal) {
       case SIGINT:
       case SIGHUP:
