$NetBSD: patch-chrome_common_chrome__switches.cc,v 1.1 2025/02/06 09:57:57 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/common/chrome_switches.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ chrome/common/chrome_switches.cc
@@ -892,7 +892,7 @@ const char kAllowNaClSocketAPI[] = "allo
 #endif
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 const char kEnableNewAppMenuIcon[] = "enable-new-app-menu-icon";
 
 // Causes the browser to launch directly in guest mode.
@@ -902,7 +902,7 @@ const char kGuest[] = "guest";
 const char kForceNtpMobilePromo[] = "force-ntp-mobile-promo";
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 // Writes open and installed web apps for each profile to the specified file
 // without launching a new browser window or tab. Pass a absolute file path to
 // specify where to output the information. Can be used together with optional
