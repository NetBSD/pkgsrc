$NetBSD: patch-chrome_browser_themes_theme__service.cc,v 1.19 2026/05/10 15:29:51 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/themes/theme_service.cc.orig	2026-04-28 23:05:57.000000000 +0200
+++ chrome/browser/themes/theme_service.cc
@@ -75,7 +75,7 @@
 #include "extensions/browser/extension_registry_observer.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "base/time/time.h"
 #include "ui/linux/linux_ui.h"
 #include "ui/linux/linux_ui_factory.h"
@@ -260,7 +260,7 @@ std::unique_ptr<ui::ThemeProvider> Theme
 // static
 void ThemeService::RegisterProfilePrefs(
     user_prefs::PrefRegistrySyncable* registry) {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   registry->RegisterIntegerPref(prefs::kSystemTheme,
                                 static_cast<int>(ui::GetDefaultSystemTheme()));
 #endif
@@ -391,7 +391,7 @@ CustomThemeSupplier* ThemeService::GetTh
 }
 
 bool ThemeService::ShouldUseCustomFrame() const {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (!ui::OzonePlatform::GetInstance()
            ->GetPlatformRuntimeProperties()
            .supports_server_side_window_decorations) {
