$NetBSD: patch-components_regional__capabilities_regional__capabilities__service.h,v 1.9 2026/09/02 13:13:29 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/regional_capabilities/regional_capabilities_service.h.orig	2026-08-31 22:47:51.000000000 +0000
+++ components/regional_capabilities/regional_capabilities_service.h
@@ -123,7 +123,7 @@ class RegionalCapabilitiesService : publ
   static bool IsInAnySearchEngineChoiceScreenRegion(
       const country_codes::CountryId& tested_country_id);
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Returns whether the country obtained from the client is associated with
   // a region in which we can show a search engine choice screen.
   //
