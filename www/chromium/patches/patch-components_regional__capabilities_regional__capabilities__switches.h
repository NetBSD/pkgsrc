$NetBSD: patch-components_regional__capabilities_regional__capabilities__switches.h,v 1.7 2025/10/16 19:43:27 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/regional_capabilities/regional_capabilities_switches.h.orig	2025-10-13 21:41:26.000000000 +0000
+++ components/regional_capabilities/regional_capabilities_switches.h
@@ -47,7 +47,7 @@ BASE_DECLARE_FEATURE(kMitigateLegacySear
 BASE_DECLARE_FEATURE(kResolveRegionalCapabilitiesFromDevice);
 #endif
 
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD) 
 // Use finch permanent country instead of finch latest country for fetching
 // country ID.
 BASE_DECLARE_FEATURE(kUseFinchPermanentCountryForFetchCountryId);
