$NetBSD: patch-components_regional__capabilities_regional__capabilities__service.cc,v 1.1 2025/05/16 16:08:23 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/regional_capabilities/regional_capabilities_service.cc.orig	2025-05-05 19:21:24.000000000 +0000
+++ components/regional_capabilities/regional_capabilities_service.cc
@@ -216,7 +216,7 @@ std::optional<CountryId> RegionalCapabil
     return persisted_country_id;
   }
 
-#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (base::FeatureList::IsEnabled(switches::kClearPrefForUnknownCountry)) {
     profile_prefs_->ClearPref(country_codes::kCountryIDAtInstall);
     base::UmaHistogramEnumeration(kUnknownCountryIdStored,
