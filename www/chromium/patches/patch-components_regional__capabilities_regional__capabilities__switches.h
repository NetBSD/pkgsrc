$NetBSD: patch-components_regional__capabilities_regional__capabilities__switches.h,v 1.9 2025/11/20 08:36:13 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/regional_capabilities/regional_capabilities_switches.h.orig	2025-11-14 20:31:45.000000000 +0000
+++ components/regional_capabilities/regional_capabilities_switches.h
@@ -53,7 +53,7 @@ BASE_DECLARE_FEATURE(kRestrictLegacySear
 BASE_DECLARE_FEATURE(kResolveRegionalCapabilitiesFromDevice);
 #endif
 
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD) 
 // Use finch permanent country instead of finch latest country for fetching
 // country ID.
 BASE_DECLARE_FEATURE(kUseFinchPermanentCountryForFetchCountryId);
