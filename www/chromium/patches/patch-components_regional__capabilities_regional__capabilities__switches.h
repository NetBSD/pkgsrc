$NetBSD: patch-components_regional__capabilities_regional__capabilities__switches.h,v 1.5 2025/09/08 13:24:24 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/regional_capabilities/regional_capabilities_switches.h.orig	2025-08-29 18:50:09.000000000 +0000
+++ components/regional_capabilities/regional_capabilities_switches.h
@@ -33,7 +33,7 @@ inline constexpr char kEeaListCountryOve
 BASE_DECLARE_FEATURE(kMitigateLegacySearchEnginePromoOverlap);
 #endif
 
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD) 
 // Use finch permanent country instead of finch latest country for fetching
 // country ID.
 BASE_DECLARE_FEATURE(kUseFinchPermanentCountryForFetchCountryId);
