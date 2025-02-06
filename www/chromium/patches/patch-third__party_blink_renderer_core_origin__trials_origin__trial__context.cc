$NetBSD: patch-third__party_blink_renderer_core_origin__trials_origin__trial__context.cc,v 1.1 2025/02/06 09:58:23 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/blink/renderer/core/origin_trials/origin_trial_context.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ third_party/blink/renderer/core/origin_trials/origin_trial_context.cc
@@ -553,7 +553,7 @@ bool OriginTrialContext::CanEnableTrialF
   }
 
   if (trial_name == "TranslationAPI") {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     return base::FeatureList::IsEnabled(features::kEnableTranslationAPI);
 #else
     return false;
