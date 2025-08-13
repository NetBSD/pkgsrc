$NetBSD: patch-chrome_browser_chrome__browser__field__trials.cc,v 1.5 2025/08/13 07:44:17 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/chrome_browser_field_trials.cc.orig	2025-07-29 22:51:44.000000000 +0000
+++ chrome/browser/chrome_browser_field_trials.cc
@@ -44,7 +44,7 @@
 #include "chromeos/ash/services/multidevice_setup/public/cpp/first_run_field_trial.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "base/nix/xdg_util.h"
 #include "ui/base/ui_base_features.h"
 #endif  // BUILDFLAG(IS_LINUX)
@@ -100,7 +100,7 @@ void ChromeBrowserFieldTrials::RegisterF
     base::FeatureList* feature_list) {
   variations::FeatureOverrides feature_overrides(*feature_list);
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // On Linux/Desktop platform variants, such as ozone/wayland, some features
   // might need to be disabled as per OzonePlatform's runtime properties.
   // OzonePlatform selection and initialization, in turn, depend on Chrome flags
