$NetBSD: patch-chrome_common_chrome__switches.h,v 1.28 2026/10/02 11:43:26 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/common/chrome_switches.h.orig	2026-09-22 00:09:16.000000000 +0000
+++ chrome/common/chrome_switches.h
@@ -976,7 +976,7 @@ inline constexpr char kDebugPrint[] = "d
 #endif
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 // Causes the browser to launch directly in guest mode.
 inline constexpr char kGuest[] = "guest";
 
@@ -1044,7 +1044,7 @@ inline constexpr char kGlicGuestUrlPrese
 
 inline constexpr char kGlicGuestUrlPresetProd[] = "glic-guest-url-preset-prod";
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 // Writes open and installed web apps for each profile to the specified file
 // without launching a new browser window or tab. Pass a absolute file path
 // to specify where to output the information. Can be used together with
