$NetBSD: patch-chrome_common_chrome__switches.cc,v 1.23 2026/07/08 13:42:20 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/common/chrome_switches.cc.orig	2026-07-06 22:58:46.000000000 +0000
+++ chrome/common/chrome_switches.cc
@@ -932,7 +932,7 @@ const char kDebugPrint[] = "debug-print"
 #endif
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 
 // Causes the browser to launch directly in guest mode.
 const char kGuest[] = "guest";
@@ -980,7 +980,7 @@ const char kGlicGuestUrlPresetStaging[] 
 const char kGlicGuestUrlPresetPreprod[] = "glic-guest-url-preset-preprod";
 const char kGlicGuestUrlPresetProd[] = "glic-guest-url-preset-prod";
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 // Writes open and installed web apps for each profile to the specified file
 // without launching a new browser window or tab. Pass a absolute file path
 // to specify where to output the information. Can be used together with
