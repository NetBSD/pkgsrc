$NetBSD: patch-components_regional__capabilities_regional__capabilities__switches.cc,v 1.12 2025/12/23 13:22:18 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/regional_capabilities/regional_capabilities_switches.cc.orig	2025-12-17 23:05:18.000000000 +0000
+++ components/regional_capabilities/regional_capabilities_switches.cc
@@ -23,7 +23,7 @@ BASE_FEATURE(kResolveRegionalCapabilitie
              base::FEATURE_ENABLED_BY_DEFAULT);
 #endif
 
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD) 
 BASE_FEATURE(kUseFinchPermanentCountryForFetchCountryId,
              "UseFinchPermanentCountyForFetchCountryId",
              base::FEATURE_ENABLED_BY_DEFAULT);
