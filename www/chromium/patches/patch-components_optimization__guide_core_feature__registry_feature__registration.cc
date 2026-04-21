$NetBSD: patch-components_optimization__guide_core_feature__registry_feature__registration.cc,v 1.11 2026/04/21 15:21:14 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/optimization_guide/core/feature_registry/feature_registration.cc.orig	2026-04-14 23:31:37.000000000 +0200
+++ components/optimization_guide/core/feature_registry/feature_registration.cc
@@ -80,7 +80,7 @@ BASE_FEATURE(kProductSpecificationsMqlsL
 
 BASE_FEATURE(kFormsClassificationsMqlsLogging,
              BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) ||
-                     BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+                     BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
                  ? base::FEATURE_ENABLED_BY_DEFAULT
                  : base::FEATURE_DISABLED_BY_DEFAULT);
 
