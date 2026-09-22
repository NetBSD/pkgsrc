$NetBSD: patch-chrome_app_chrome__main.cc,v 1.26 2026/09/22 13:41:18 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/app/chrome_main.cc.orig	2026-09-14 22:17:16.000000000 +0000
+++ chrome/app/chrome_main.cc
@@ -36,11 +36,11 @@
 #include "chrome/common/mac/detect_inappropriate_exit.h"
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "base/base_switches.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/app/chrome_main_linux.h"
 #endif
 
@@ -110,7 +110,7 @@ int ChromeMain(int argc, const char** ar
 #error Unknown platform.
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   PossiblyDetermineFallbackChromeChannel(argv[0]);
 #endif
 
@@ -183,7 +183,7 @@ int ChromeMain(int argc, const char** ar
   SetUpBundleOverrides();
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   AppendExtraArgumentsToCommandLine(command_line);
 #endif
 
