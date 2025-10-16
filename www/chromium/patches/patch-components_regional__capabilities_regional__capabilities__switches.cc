$NetBSD: patch-components_regional__capabilities_regional__capabilities__switches.cc,v 1.7 2025/10/16 19:43:27 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/regional_capabilities/regional_capabilities_switches.cc.orig	2025-10-13 21:41:26.000000000 +0000
+++ components/regional_capabilities/regional_capabilities_switches.cc
@@ -21,7 +21,7 @@ BASE_FEATURE(kResolveRegionalCapabilitie
              base::FEATURE_ENABLED_BY_DEFAULT);
 #endif
 
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD) 
 BASE_FEATURE(kUseFinchPermanentCountryForFetchCountryId,
              "UseFinchPermanentCountyForFetchCountryId",
              base::FEATURE_DISABLED_BY_DEFAULT);
