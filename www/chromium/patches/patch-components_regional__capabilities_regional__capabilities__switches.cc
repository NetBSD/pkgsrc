$NetBSD: patch-components_regional__capabilities_regional__capabilities__switches.cc,v 1.6 2025/09/12 16:02:27 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/regional_capabilities/regional_capabilities_switches.cc.orig	2025-09-08 23:21:33.000000000 +0000
+++ components/regional_capabilities/regional_capabilities_switches.cc
@@ -18,7 +18,7 @@ BASE_FEATURE(kMitigateLegacySearchEngine
              base::FEATURE_DISABLED_BY_DEFAULT);
 #endif
 
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD) 
 BASE_FEATURE(kUseFinchPermanentCountryForFetchCountryId,
              "UseFinchPermanentCountyForFetchCountryId",
              base::FEATURE_DISABLED_BY_DEFAULT);
