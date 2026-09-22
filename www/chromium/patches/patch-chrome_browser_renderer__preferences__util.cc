$NetBSD: patch-chrome_browser_renderer__preferences__util.cc,v 1.26 2026/09/22 13:41:20 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/renderer_preferences_util.cc.orig	2026-09-14 22:17:16.000000000 +0000
+++ chrome/browser/renderer_preferences_util.cc
@@ -38,12 +38,12 @@
 #include "ui/base/ui_base_features.h"
 #include "ui/native_theme/native_theme.h"
 
-#if defined(USE_AURA) && BUILDFLAG(IS_LINUX)
+#if defined(USE_AURA) && (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD))
 #include "chrome/browser/themes/theme_service.h"
 #include "chrome/browser/themes/theme_service_factory.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "base/environment.h"
 #include "base/nix/xdg_util.h"
 #include "ui/linux/linux_ui.h"
@@ -112,7 +112,7 @@ void UpdateFromSystemSettings(blink::Ren
                               Profile* profile) {
   const PrefService* pref_service = profile->GetPrefs();
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   content::UpdateFontRendererPreferencesFromSystemSettings(prefs);
 #endif
   prefs->focus_ring_color = BUILDFLAG(IS_MAC) ? SkColorSetRGB(0x00, 0x5F, 0xCC)
@@ -126,7 +126,7 @@ void UpdateFromSystemSettings(blink::Ren
   prefs->inactive_selection_fg_color = SK_ColorBLACK;
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (auto* linux_ui_theme = ui::LinuxUiTheme::GetForProfile(profile)) {
     if (ThemeServiceFactory::GetForProfile(profile)->UsingSystemTheme()) {
       linux_ui_theme->GetFocusRingColor(&prefs->focus_ring_color);
@@ -143,7 +143,7 @@ void UpdateFromSystemSettings(blink::Ren
 #endif  // BUILDFLAG(IS_LINUX)
 #endif  // BUILDFLAG(USE_AURA)
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (auto* linux_ui = ui::LinuxUi::instance()) {
     prefs->middle_click_paste_allowed = linux_ui->PrimaryPasteEnabled();
   }
@@ -245,7 +245,7 @@ void UpdateFromSystemSettings(blink::Ren
   prefs->view_source_line_wrap_enabled =
       pref_service->GetBoolean(prefs::kViewSourceLineWrappingEnabled);
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Check the session type from the environment variable (XDG_SESSION_TYPE)
   // instead of the Ozone platform, because XWayland sessions still require
   // the portal eye dropper for reliable screen capture.
