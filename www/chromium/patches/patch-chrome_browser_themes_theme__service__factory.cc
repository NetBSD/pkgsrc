$NetBSD: patch-chrome_browser_themes_theme__service__factory.cc,v 1.1 2025/02/06 09:57:52 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/themes/theme_service_factory.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ chrome/browser/themes/theme_service_factory.cc
@@ -27,11 +27,11 @@
 
 // TODO(crbug.com/40118868): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/themes/theme_service_aura_linux.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "ui/linux/linux_ui_factory.h"
 #endif
 
@@ -106,7 +106,7 @@ ThemeServiceFactory::~ThemeServiceFactor
 
 KeyedService* ThemeServiceFactory::BuildServiceInstanceFor(
     content::BrowserContext* profile) const {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   using ThemeService = ThemeServiceAuraLinux;
 #endif
 
@@ -120,9 +120,9 @@ void ThemeServiceFactory::RegisterProfil
     user_prefs::PrefRegistrySyncable* registry) {
 // TODO(crbug.com/40118868): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
   ui::SystemTheme default_system_theme = ui::SystemTheme::kDefault;
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   default_system_theme = ui::GetDefaultSystemTheme();
 #endif
   registry->RegisterIntegerPref(prefs::kSystemTheme,
