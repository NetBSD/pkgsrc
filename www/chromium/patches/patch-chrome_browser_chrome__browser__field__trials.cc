$NetBSD: patch-chrome_browser_chrome__browser__field__trials.cc,v 1.7 2025/09/12 16:02:21 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/chrome_browser_field_trials.cc.orig	2025-09-08 23:21:33.000000000 +0000
+++ chrome/browser/chrome_browser_field_trials.cc
@@ -45,7 +45,7 @@
 #include "chromeos/ash/services/multidevice_setup/public/cpp/first_run_field_trial.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "base/nix/xdg_util.h"
 #include "ui/base/ui_base_features.h"
 #endif  // BUILDFLAG(IS_LINUX)
@@ -101,7 +101,7 @@ void ChromeBrowserFieldTrials::RegisterF
     base::FeatureList* feature_list) {
   variations::FeatureOverrides feature_overrides(*feature_list);
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // On Linux/Desktop platform variants, such as ozone/wayland, some features
   // might need to be disabled as per OzonePlatform's runtime properties.
   // OzonePlatform selection and initialization, in turn, depend on Chrome flags
