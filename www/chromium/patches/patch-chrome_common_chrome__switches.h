$NetBSD: patch-chrome_common_chrome__switches.h,v 1.15 2026/02/15 09:04:01 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/common/chrome_switches.h.orig	2026-02-03 22:07:10.000000000 +0000
+++ chrome/common/chrome_switches.h
@@ -291,7 +291,7 @@ extern const char kDebugPrint[];
 #endif
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 extern const char kEnableNewAppMenuIcon[];
 extern const char kGuest[];
 extern const char kForceNtpMobilePromo[];
@@ -314,7 +314,7 @@ extern const char kGlicResetMultiInstanc
 extern const char kGlicForceG1StatusForMultiInstance[];
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 extern const char kListApps[];
 extern const char kProfileBaseName[];
 extern const char kProfileManagementAttributes[];
