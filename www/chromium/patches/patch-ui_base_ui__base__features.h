$NetBSD: patch-ui_base_ui__base__features.h,v 1.15 2026/10/13 13:16:51 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- ui/base/ui_base_features.h.orig	2026-10-06 00:06:58.000000000 +0000
+++ ui/base/ui_base_features.h
@@ -155,7 +155,7 @@ COMPONENT_EXPORT(UI_BASE_FEATURES)
 BASE_DECLARE_FEATURE(kWaylandExternalBeginFrameSource);
 #endif  // BUILDFLAG(IS_OZONE)
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 COMPONENT_EXPORT(UI_BASE_FEATURES)
 BASE_DECLARE_FEATURE(kGlobalShortcutsPortalPreferredTrigger);
 #endif
@@ -347,7 +347,7 @@ BASE_DECLARE_FEATURE(kChromeDarkNeutrals
 COMPONENT_EXPORT(UI_BASE_FEATURES)
 BASE_DECLARE_FEATURE(kDarkModeSurfaceTokens);
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 // When enabled, reads the system accent color from the xdg-desktop-portal (the
 // org.freedesktop.appearance "accent-color" setting) and applies it as the
 // NativeTheme user color.
