$NetBSD: patch-components_regional__capabilities_regional__capabilities__service.cc,v 1.22 2026/11/19 19:45:59 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/regional_capabilities/regional_capabilities_service.cc.orig	2026-11-11 21:01:38.000000000 +0000
+++ components/regional_capabilities/regional_capabilities_service.cc
@@ -460,7 +460,7 @@ bool RegionalCapabilitiesService::IsInAn
       .choice_screen_eligibility_config.has_value();
 }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // static
 bool RegionalCapabilitiesService::IsInAnySearchEngineChoiceScreenRegion(
     Client& client) {
