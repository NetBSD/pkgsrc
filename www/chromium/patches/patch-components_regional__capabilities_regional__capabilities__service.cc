$NetBSD: patch-components_regional__capabilities_regional__capabilities__service.cc,v 1.10 2026/06/08 13:12:38 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/regional_capabilities/regional_capabilities_service.cc.orig	2026-05-28 23:24:11.000000000 +0000
+++ components/regional_capabilities/regional_capabilities_service.cc
@@ -413,7 +413,7 @@ bool RegionalCapabilitiesService::IsInSe
       .choice_screen_eligibility_config.has_value();
 }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // static
 bool RegionalCapabilitiesService::IsInSearchEngineChoiceScreenRegion(
     Client& client) {
