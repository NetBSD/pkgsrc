$NetBSD: patch-chrome_common_chrome__switches.h,v 1.21 2026/06/08 13:12:36 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/common/chrome_switches.h.orig	2026-05-28 23:24:11.000000000 +0000
+++ chrome/common/chrome_switches.h
@@ -286,7 +286,7 @@ extern const char kDebugPrint[];
 #endif
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 extern const char kGuest[];
 #endif
 
@@ -308,7 +308,7 @@ extern const char kGlicGuestUrlPresetSta
 extern const char kGlicGuestUrlPresetPreprod[];
 extern const char kGlicGuestUrlPresetProd[];
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 extern const char kListApps[];
 extern const char kProfileBaseName[];
 extern const char kProfileManagementAttributes[];
