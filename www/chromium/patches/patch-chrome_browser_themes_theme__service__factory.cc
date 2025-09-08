$NetBSD: patch-chrome_browser_themes_theme__service__factory.cc,v 1.6 2025/09/08 13:24:20 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/themes/theme_service_factory.cc.orig	2025-08-29 18:50:09.000000000 +0000
+++ chrome/browser/themes/theme_service_factory.cc
@@ -25,7 +25,7 @@
 #include "chrome/browser/themes/theme_helper_win.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/themes/theme_service_aura_linux.h"
 #include "ui/linux/linux_ui_factory.h"
 #endif
@@ -105,7 +105,7 @@ ThemeServiceFactory::~ThemeServiceFactor
 std::unique_ptr<KeyedService>
 ThemeServiceFactory::BuildServiceInstanceForBrowserContext(
     content::BrowserContext* profile) const {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   using ThemeService = ThemeServiceAuraLinux;
 #endif
 
@@ -117,7 +117,7 @@ ThemeServiceFactory::BuildServiceInstanc
 
 void ThemeServiceFactory::RegisterProfilePrefs(
     user_prefs::PrefRegistrySyncable* registry) {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   registry->RegisterIntegerPref(prefs::kSystemTheme,
                                 static_cast<int>(ui::GetDefaultSystemTheme()));
 #endif
