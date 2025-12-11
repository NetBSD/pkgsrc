$NetBSD: patch-chrome_common_chrome__switches.cc,v 1.11 2025/12/11 09:13:34 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/common/chrome_switches.cc.orig	2025-11-19 21:40:05.000000000 +0000
+++ chrome/common/chrome_switches.cc
@@ -934,7 +934,7 @@ const char kDebugPrint[] = "debug-print"
 #endif
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 const char kEnableNewAppMenuIcon[] = "enable-new-app-menu-icon";
 
 // Causes the browser to launch directly in guest mode.
@@ -970,7 +970,7 @@ const char kGlicHostLogging[] = "glic-ho
 const char kGlicAdminRedirectPatterns[] = "glic-admin-redirect-patterns";
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 // Writes open and installed web apps for each profile to the specified file
 // without launching a new browser window or tab. Pass a absolute file path
 // to specify where to output the information. Can be used together with
