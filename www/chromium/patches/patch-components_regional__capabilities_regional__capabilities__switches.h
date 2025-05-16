$NetBSD: patch-components_regional__capabilities_regional__capabilities__switches.h,v 1.1 2025/05/16 16:08:23 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/regional_capabilities/regional_capabilities_switches.h.orig	2025-05-05 19:21:24.000000000 +0000
+++ components/regional_capabilities/regional_capabilities_switches.h
@@ -25,7 +25,7 @@ inline constexpr char kSearchEngineChoic
 inline constexpr char kDefaultListCountryOverride[] = "DEFAULT_EEA";
 inline constexpr char kEeaListCountryOverride[] = "EEA_ALL";
 
-#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // When an invalid `country_codes::CountryId` is stored in prefs and this
 // feature is enabled the pref will be cleared allowing a valid country to be
 // set again.
