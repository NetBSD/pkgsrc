$NetBSD: patch-src_3rdparty_chromium_components_regional__capabilities_regional__capabilities__switches.cc,v 1.1 2026/04/30 06:39:39 adam Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/components/regional_capabilities/regional_capabilities_switches.cc.orig	2026-03-16 11:40:07.000000000 +0000
+++ src/3rdparty/chromium/components/regional_capabilities/regional_capabilities_switches.cc
@@ -18,7 +18,7 @@ BASE_FEATURE(kMitigateLegacySearchEngine
              base::FEATURE_DISABLED_BY_DEFAULT);
 #endif
 
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kUseFinchPermanentCountryForFetchCountryId,
              "UseFinchPermanentCountyForFetchCountryId",
              base::FEATURE_DISABLED_BY_DEFAULT);
