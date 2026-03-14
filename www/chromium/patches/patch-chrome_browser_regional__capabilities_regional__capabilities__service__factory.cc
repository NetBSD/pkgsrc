$NetBSD: patch-chrome_browser_regional__capabilities_regional__capabilities__service__factory.cc,v 1.12 2026/03/14 12:40:27 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/regional_capabilities/regional_capabilities_service_factory.cc.orig	2026-03-11 22:12:25.000000000 +0000
+++ chrome/browser/regional_capabilities/regional_capabilities_service_factory.cc
@@ -21,7 +21,7 @@
 #include "chrome/browser/regional_capabilities/regional_capabilities_service_client_chromeos.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/regional_capabilities/regional_capabilities_service_client_linux.h"
 #endif
 
@@ -72,7 +72,7 @@ RegionalCapabilitiesServiceFactory::Buil
 #elif BUILDFLAG(IS_CHROMEOS)
       std::make_unique<RegionalCapabilitiesServiceClientChromeOS>(
           g_browser_process->variations_service());
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       std::make_unique<RegionalCapabilitiesServiceClientLinux>(
           g_browser_process->variations_service());
 #else
