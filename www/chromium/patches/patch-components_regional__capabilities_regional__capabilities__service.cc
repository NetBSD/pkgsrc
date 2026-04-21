$NetBSD: patch-components_regional__capabilities_regional__capabilities__service.cc,v 1.7 2026/04/21 15:21:14 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/regional_capabilities/regional_capabilities_service.cc.orig	2026-04-14 23:31:37.000000000 +0200
+++ components/regional_capabilities/regional_capabilities_service.cc
@@ -413,7 +413,7 @@ bool RegionalCapabilitiesService::IsInSe
       .choice_screen_eligibility_config.has_value();
 }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // static
 bool RegionalCapabilitiesService::IsInSearchEngineChoiceScreenRegion(
     Client& client) {
