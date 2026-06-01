$NetBSD: patch-components_regional__capabilities_regional__capabilities__service.cc,v 1.9 2026/06/01 10:09:13 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/regional_capabilities/regional_capabilities_service.cc.orig	2026-05-26 20:39:02.000000000 +0000
+++ components/regional_capabilities/regional_capabilities_service.cc
@@ -413,7 +413,7 @@ bool RegionalCapabilitiesService::IsInSe
       .choice_screen_eligibility_config.has_value();
 }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // static
 bool RegionalCapabilitiesService::IsInSearchEngineChoiceScreenRegion(
     Client& client) {
