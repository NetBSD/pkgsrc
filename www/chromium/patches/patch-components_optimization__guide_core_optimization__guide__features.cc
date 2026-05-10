$NetBSD: patch-components_optimization__guide_core_optimization__guide__features.cc,v 1.19 2026/05/10 15:29:55 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/optimization_guide/core/optimization_guide_features.cc.orig	2026-04-28 23:05:57.000000000 +0200
+++ components/optimization_guide/core/optimization_guide_features.cc
@@ -97,7 +97,7 @@ BASE_FEATURE(kOptimizationGuideModelExec
 // Whether to use the on device model service in optimization guide.
 BASE_FEATURE(kOptimizationGuideOnDeviceModel,
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT);
 #else
              base::FEATURE_DISABLED_BY_DEFAULT);
