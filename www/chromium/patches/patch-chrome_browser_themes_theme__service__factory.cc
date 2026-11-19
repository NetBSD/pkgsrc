$NetBSD: patch-chrome_browser_themes_theme__service__factory.cc,v 1.33 2026/11/19 19:45:54 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/themes/theme_service_factory.cc.orig	2026-11-11 21:01:38.000000000 +0000
+++ chrome/browser/themes/theme_service_factory.cc
@@ -28,7 +28,7 @@
 #include "chrome/browser/themes/theme_helper_win.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/themes/theme_service_aura_linux.h"
 #endif
 
@@ -111,7 +111,7 @@ ThemeServiceFactory::~ThemeServiceFactor
 std::unique_ptr<KeyedService>
 ThemeServiceFactory::BuildServiceInstanceForBrowserContext(
     content::BrowserContext* profile) const {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   using ThemeService = ThemeServiceAuraLinux;
 #elif BUILDFLAG(IS_ANDROID)
   using ThemeService = ThemeServiceAndroid;
