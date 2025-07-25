$NetBSD: patch-chrome_browser_chrome__browser__field__trials.cc,v 1.4 2025/07/25 16:17:10 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/chrome_browser_field_trials.cc.orig	2025-07-21 19:32:31.000000000 +0000
+++ chrome/browser/chrome_browser_field_trials.cc
@@ -38,7 +38,7 @@
 #include "chromeos/ash/services/multidevice_setup/public/cpp/first_run_field_trial.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "base/nix/xdg_util.h"
 #include "ui/base/ui_base_features.h"
 #endif  // BUILDFLAG(IS_LINUX)
@@ -118,7 +118,7 @@ void ChromeBrowserFieldTrials::RegisterS
 #endif  // BUILDFLAG(IS_ANDROID)
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // On Linux/Desktop platform variants, such as ozone/wayland, some features
 // might need to be disabled as per OzonePlatform's runtime properties.
 // OzonePlatform selection and initialization, in turn, depend on Chrome flags
