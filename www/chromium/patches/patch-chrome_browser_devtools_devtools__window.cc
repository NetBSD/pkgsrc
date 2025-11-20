$NetBSD: patch-chrome_browser_devtools_devtools__window.cc,v 1.2 2025/11/20 08:36:06 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/devtools/devtools_window.cc.orig	2025-11-14 20:31:45.000000000 +0000
+++ chrome/browser/devtools/devtools_window.cc
@@ -566,7 +566,7 @@ void DevToolsWindow::RegisterProfilePref
       prefs::kDevToolsGoogleDeveloperProgramProfileAvailability,
       /* enabled */ 0);
 #if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_MAC)
+    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   registry->RegisterListPref(prefs::kDeveloperToolsAvailabilityAllowlist);
   registry->RegisterListPref(prefs::kDeveloperToolsAvailabilityBlocklist);
 #endif  // BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) ||
