$NetBSD: patch-chrome_browser_chrome__browser__field__trials.cc,v 1.19 2026/05/10 15:29:49 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/chrome_browser_field_trials.cc.orig	2026-04-28 23:05:57.000000000 +0200
+++ chrome/browser/chrome_browser_field_trials.cc
@@ -53,12 +53,12 @@
 #include "chromeos/ash/services/multidevice_setup/public/cpp/first_run_field_trial.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "base/nix/xdg_util.h"
 #include "ui/base/ui_base_features.h"
 #endif  // BUILDFLAG(IS_LINUX)
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "base/check_deref.h"
 #include "chrome/browser/first_run/first_run.h"
 #include "chrome/browser/signin/before_fre_refresh_hats_field_trial.h"
@@ -94,7 +94,7 @@ void ChromeBrowserFieldTrials::SetUpClie
   }
 #endif
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // This trial is client controlled on Mac and Linux because the survey is
   // triggered on the very first run of Chrome. These platforms do not support
   // variations seed on the first run.
@@ -125,7 +125,7 @@ void ChromeBrowserFieldTrials::RegisterF
     base::FeatureList* feature_list) {
   variations::FeatureOverrides feature_overrides(*feature_list);
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // On Linux/Desktop platform variants, such as ozone/wayland, some features
   // might need to be disabled as per OzonePlatform's runtime properties.
   // OzonePlatform selection and initialization, in turn, depend on Chrome flags
