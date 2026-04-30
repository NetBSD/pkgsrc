$NetBSD: patch-src_3rdparty_chromium_components_regional__capabilities_regional__capabilities__switches.h,v 1.1 2026/04/30 06:39:39 adam Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/components/regional_capabilities/regional_capabilities_switches.h.orig	2026-03-16 11:40:07.000000000 +0000
+++ src/3rdparty/chromium/components/regional_capabilities/regional_capabilities_switches.h
@@ -33,7 +33,7 @@ inline constexpr char kEeaListCountryOve
 BASE_DECLARE_FEATURE(kMitigateLegacySearchEnginePromoOverlap);
 #endif
 
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Use finch permanent country instead of finch latest country for fetching
 // country ID.
 BASE_DECLARE_FEATURE(kUseFinchPermanentCountryForFetchCountryId);
