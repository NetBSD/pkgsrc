$NetBSD: patch-chrome_common_chrome__switches.cc,v 1.26 2026/09/22 13:41:23 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/common/chrome_switches.cc.orig	2026-09-14 22:17:16.000000000 +0000
+++ chrome/common/chrome_switches.cc
@@ -948,7 +948,7 @@ const char kDebugPrint[] = "debug-print"
 #endif
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 
 // Causes the browser to launch directly in guest mode.
 const char kGuest[] = "guest";
@@ -996,7 +996,7 @@ const char kGlicGuestUrlPresetStaging[] 
 const char kGlicGuestUrlPresetPreprod[] = "glic-guest-url-preset-preprod";
 const char kGlicGuestUrlPresetProd[] = "glic-guest-url-preset-prod";
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 // Writes open and installed web apps for each profile to the specified file
 // without launching a new browser window or tab. Pass a absolute file path
 // to specify where to output the information. Can be used together with
