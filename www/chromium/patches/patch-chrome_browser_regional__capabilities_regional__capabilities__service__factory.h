$NetBSD: patch-chrome_browser_regional__capabilities_regional__capabilities__service__factory.h,v 1.9 2026/09/02 13:13:24 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/regional_capabilities/regional_capabilities_service_factory.h.orig	2026-08-31 22:47:51.000000000 +0000
+++ chrome/browser/regional_capabilities/regional_capabilities_service_factory.h
@@ -31,7 +31,7 @@ class RegionalCapabilitiesServiceFactory
 
   static RegionalCapabilitiesServiceFactory* GetInstance();
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Returns whether the system profile is in a region where we can show a
   // search engine choice screen. If the profile is not a system profile, this
   // function crashes. Used for clients associated with system profiles (where
