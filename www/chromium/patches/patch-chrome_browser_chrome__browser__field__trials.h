$NetBSD: patch-chrome_browser_chrome__browser__field__trials.h,v 1.1 2025/02/06 09:57:45 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/chrome_browser_field_trials.h.orig	2024-12-17 17:58:49.000000000 +0000
+++ chrome/browser/chrome_browser_field_trials.h
@@ -33,7 +33,7 @@ class ChromeBrowserFieldTrials : public 
       const variations::EntropyProviders& entropy_providers,
       base::FeatureList* feature_list) override;
   void RegisterSyntheticTrials() override;
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   void RegisterFeatureOverrides(base::FeatureList* feature_list) override;
 #endif
 
