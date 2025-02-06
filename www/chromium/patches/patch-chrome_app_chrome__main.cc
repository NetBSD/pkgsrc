$NetBSD: patch-chrome_app_chrome__main.cc,v 1.1 2025/02/06 09:57:44 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/app/chrome_main.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ chrome/app/chrome_main.cc
@@ -30,11 +30,11 @@
 #include "chrome/app/chrome_main_mac.h"
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "base/base_switches.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/app/chrome_main_linux.h"
 #endif
 
@@ -55,7 +55,7 @@
 #endif  // BUILDFLAG(IS_WIN)
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 #define ENABLE_OLD_HEADLESS
 #endif
 
@@ -120,7 +120,7 @@ int ChromeMain(int argc, const char** ar
 #error Unknown platform.
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   PossiblyDetermineFallbackChromeChannel(argv[0]);
 #endif
 
@@ -186,7 +186,7 @@ int ChromeMain(int argc, const char** ar
   SetUpBundleOverrides();
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   AppendExtraArgumentsToCommandLine(command_line);
 #endif
 
