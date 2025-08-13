$NetBSD: patch-components_regional__capabilities_regional__capabilities__service.cc,v 1.4 2025/08/13 07:44:23 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/regional_capabilities/regional_capabilities_service.cc.orig	2025-07-29 22:51:44.000000000 +0000
+++ components/regional_capabilities/regional_capabilities_service.cc
@@ -234,7 +234,7 @@ std::optional<CountryId> RegionalCapabil
     return persisted_country_id;
   }
 
-#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (base::FeatureList::IsEnabled(switches::kClearPrefForUnknownCountry)) {
     profile_prefs_->ClearPref(prefs::kCountryIDAtInstall);
     base::UmaHistogramEnumeration(kUnknownCountryIdStored,
