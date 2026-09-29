$NetBSD: patch-chrome_browser_chrome__browser__field__trials.cc,v 1.27 2026/09/29 07:42:47 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/chrome_browser_field_trials.cc.orig	2026-09-22 00:09:16.000000000 +0000
+++ chrome/browser/chrome_browser_field_trials.cc
@@ -60,7 +60,7 @@
 #include "chromeos/ash/services/multidevice_setup/public/cpp/first_run_field_trial.h"
 #endif
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "base/check_deref.h"
 #include "chrome/browser/first_run/first_run.h"
 #include "chrome/browser/signin/first_run_desktop_refresh_field_trial.h"
@@ -96,7 +96,7 @@ void ChromeBrowserFieldTrials::SetUpClie
   }
 #endif
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // This trial is client controlled on Mac and Linux because the first run
   // experience is shown on the very first run of Chrome. These platforms do not
   // support variations seed on the first run.
