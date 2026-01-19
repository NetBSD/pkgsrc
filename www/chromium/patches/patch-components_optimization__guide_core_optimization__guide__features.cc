$NetBSD: patch-components_optimization__guide_core_optimization__guide__features.cc,v 1.14 2026/01/19 16:14:13 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/optimization_guide/core/optimization_guide_features.cc.orig	2026-01-07 00:50:30.000000000 +0000
+++ components/optimization_guide/core/optimization_guide_features.cc
@@ -95,7 +95,7 @@ BASE_FEATURE(kOptimizationGuideModelExec
 // Whether to use the on device model service in optimization guide.
 BASE_FEATURE(kOptimizationGuideOnDeviceModel,
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD) 
              base::FEATURE_ENABLED_BY_DEFAULT);
 #else
              base::FEATURE_DISABLED_BY_DEFAULT);
