$NetBSD: patch-third__party_blink_renderer_core_origin__trials_origin__trial__context.cc,v 1.14 2026/01/19 16:14:19 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/blink/renderer/core/origin_trials/origin_trial_context.cc.orig	2026-01-07 00:50:30.000000000 +0000
+++ third_party/blink/renderer/core/origin_trials/origin_trial_context.cc
@@ -559,7 +559,7 @@ bool OriginTrialContext::CanEnableTrialF
   }
 
   if (trial_name == "TranslationAPI") {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     return base::FeatureList::IsEnabled(features::kTranslationAPI);
 #else
     return false;
@@ -572,7 +572,7 @@ bool OriginTrialContext::CanEnableTrialF
 
   if (trial_name == "WebAppInstallation") {
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     return base::FeatureList::IsEnabled(blink::features::kWebAppInstallation);
 #else
     return false;
