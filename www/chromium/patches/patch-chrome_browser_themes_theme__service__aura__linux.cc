$NetBSD: patch-chrome_browser_themes_theme__service__aura__linux.cc,v 1.13 2025/12/23 13:22:14 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/themes/theme_service_aura_linux.cc.orig	2025-12-17 23:05:18.000000000 +0000
+++ chrome/browser/themes/theme_service_aura_linux.cc
@@ -23,7 +23,7 @@ namespace {
 ui::SystemTheme ValidateSystemTheme(ui::SystemTheme system_theme) {
   switch (system_theme) {
     case ui::SystemTheme::kDefault:
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     case ui::SystemTheme::kGtk:
     case ui::SystemTheme::kQt:
 #endif
