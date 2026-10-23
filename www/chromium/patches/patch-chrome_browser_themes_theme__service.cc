$NetBSD: patch-chrome_browser_themes_theme__service.cc,v 1.31 2026/10/23 15:05:19 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/themes/theme_service.cc.orig	2026-10-19 20:07:21.000000000 +0000
+++ chrome/browser/themes/theme_service.cc
@@ -92,7 +92,7 @@
 #include "extensions/common/extension_set.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "base/time/time.h"
 #include "ui/linux/linux_ui.h"
 #include "ui/linux/linux_ui_factory.h"
@@ -309,7 +309,7 @@ std::unique_ptr<ui::ThemeProvider> Theme
 // static
 void ThemeService::RegisterProfilePrefs(
     user_prefs::PrefRegistrySyncable* registry) {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   registry->RegisterIntegerPref(prefs::kSystemTheme,
                                 static_cast<int>(ui::GetDefaultSystemTheme()));
 #endif
@@ -442,7 +442,7 @@ CustomThemeSupplier* ThemeService::GetTh
 }
 
 bool ThemeService::ShouldUseCustomFrame() const {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (!ui::OzonePlatform::GetInstance()
            ->GetPlatformRuntimeProperties()
            .supports_server_side_window_decorations) {
