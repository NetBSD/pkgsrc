$NetBSD: patch-components_regional__capabilities_regional__capabilities__service.h,v 1.2 2026/04/21 15:21:14 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/regional_capabilities/regional_capabilities_service.h.orig	2026-04-14 23:31:37.000000000 +0200
+++ components/regional_capabilities/regional_capabilities_service.h
@@ -117,7 +117,7 @@ class RegionalCapabilitiesService : publ
   static bool IsInSearchEngineChoiceScreenRegion(
       const country_codes::CountryId& tested_country_id);
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Returns whether the country obtained from the client is associated with
   // a region in which we can show a search engine choice screen.
   //
