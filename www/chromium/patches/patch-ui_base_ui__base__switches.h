$NetBSD: patch-ui_base_ui__base__switches.h,v 1.1 2025/02/06 09:58:31 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- ui/base/ui_base_switches.h.orig	2024-12-17 17:58:49.000000000 +0000
+++ ui/base/ui_base_switches.h
@@ -27,11 +27,11 @@ COMPONENT_EXPORT(UI_BASE) extern const c
 COMPONENT_EXPORT(UI_BASE) extern const char kEnableResourcesFileSharing[];
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 COMPONENT_EXPORT(UI_BASE) extern const char kSystemFontFamily[];
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 COMPONENT_EXPORT(UI_BASE) extern const char kUiToolkitFlag[];
 COMPONENT_EXPORT(UI_BASE) extern const char kDisableGtkIme[];
 #endif
