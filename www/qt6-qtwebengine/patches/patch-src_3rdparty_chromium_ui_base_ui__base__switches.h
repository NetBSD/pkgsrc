$NetBSD: patch-src_3rdparty_chromium_ui_base_ui__base__switches.h,v 1.2 2026/04/30 06:39:45 adam Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/ui/base/ui_base_switches.h.orig	2026-03-16 11:40:07.000000000 +0000
+++ src/3rdparty/chromium/ui/base/ui_base_switches.h
@@ -22,11 +22,11 @@ COMPONENT_EXPORT(UI_BASE) extern const c
 COMPONENT_EXPORT(UI_BASE) extern const char kShowMacOverlayBorders[];
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 COMPONENT_EXPORT(UI_BASE) extern const char kSystemFontFamily[];
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 COMPONENT_EXPORT(UI_BASE) extern const char kUiToolkitFlag[];
 COMPONENT_EXPORT(UI_BASE) extern const char kGtkVersionFlag[];
 COMPONENT_EXPORT(UI_BASE) extern const char kQtVersionFlag[];
