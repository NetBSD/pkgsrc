$NetBSD: patch-ui_base_ui__base__switches.h,v 1.7 2025/09/12 16:02:37 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- ui/base/ui_base_switches.h.orig	2025-09-08 23:21:33.000000000 +0000
+++ ui/base/ui_base_switches.h
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
