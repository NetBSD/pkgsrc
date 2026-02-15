$NetBSD: patch-third__party_blink_renderer_core_origin__trials_origin__trial__context.cc,v 1.15 2026/02/15 09:04:10 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/blink/renderer/core/origin_trials/origin_trial_context.cc.orig	2026-02-03 22:07:10.000000000 +0000
+++ third_party/blink/renderer/core/origin_trials/origin_trial_context.cc
@@ -563,7 +563,7 @@ bool OriginTrialContext::CanEnableTrialF
 
   if (trial_name == "WebAppInstallation") {
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     return base::FeatureList::IsEnabled(blink::features::kWebAppInstallation);
 #else
     return false;
