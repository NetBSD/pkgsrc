$NetBSD: patch-chrome_browser_regional__capabilities_regional__capabilities__service__factory.cc,v 1.14 2026/04/21 15:21:10 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/regional_capabilities/regional_capabilities_service_factory.cc.orig	2026-04-14 23:31:37.000000000 +0200
+++ chrome/browser/regional_capabilities/regional_capabilities_service_factory.cc
@@ -21,7 +21,7 @@
 #include "chrome/browser/regional_capabilities/regional_capabilities_service_client_chromeos.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/regional_capabilities/regional_capabilities_service_client_linux.h"
 #endif
 
@@ -36,7 +36,7 @@ CreateRegionalCapabilitiesServiceClient(
 #elif BUILDFLAG(IS_CHROMEOS)
   return std::make_unique<RegionalCapabilitiesServiceClientChromeOS>(
       g_browser_process->variations_service());
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return std::make_unique<RegionalCapabilitiesServiceClientLinux>(
       g_browser_process->variations_service());
 #else
@@ -61,7 +61,7 @@ RegionalCapabilitiesServiceFactory::GetI
   return instance.get();
 }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // static
 bool RegionalCapabilitiesServiceFactory::
     IsInSearchEngineChoiceScreenRegionForSystemProfile(Profile* profile) {
