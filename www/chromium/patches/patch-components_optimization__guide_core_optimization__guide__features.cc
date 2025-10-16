$NetBSD: patch-components_optimization__guide_core_optimization__guide__features.cc,v 1.8 2025/10/16 19:43:26 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/optimization_guide/core/optimization_guide_features.cc.orig	2025-10-13 21:41:26.000000000 +0000
+++ components/optimization_guide/core/optimization_guide_features.cc
@@ -120,7 +120,7 @@ BASE_FEATURE(kOptimizationGuideModelExec
 BASE_FEATURE(kOptimizationGuideOnDeviceModel,
              "OptimizationGuideOnDeviceModel",
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD) 
              base::FEATURE_ENABLED_BY_DEFAULT);
 #else
              base::FEATURE_DISABLED_BY_DEFAULT);
