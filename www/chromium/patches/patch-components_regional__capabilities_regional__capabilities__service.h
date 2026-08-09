$NetBSD: patch-components_regional__capabilities_regional__capabilities__service.h,v 1.8 2026/08/09 06:31:15 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/regional_capabilities/regional_capabilities_service.h.orig	2026-08-05 20:17:42.000000000 +0000
+++ components/regional_capabilities/regional_capabilities_service.h
@@ -123,7 +123,7 @@ class RegionalCapabilitiesService : publ
   static bool IsInAnySearchEngineChoiceScreenRegion(
       const country_codes::CountryId& tested_country_id);
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Returns whether the country obtained from the client is associated with
   // a region in which we can show a search engine choice screen.
   //
