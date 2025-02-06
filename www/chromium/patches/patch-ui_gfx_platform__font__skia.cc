$NetBSD: patch-ui_gfx_platform__font__skia.cc,v 1.1 2025/02/06 09:58:32 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- ui/gfx/platform_font_skia.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ ui/gfx/platform_font_skia.cc
@@ -29,7 +29,7 @@
 #include "ui/gfx/system_fonts_win.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "ui/linux/linux_ui.h"
 #endif
 
@@ -167,7 +167,7 @@ void PlatformFontSkia::EnsuresDefaultFon
   weight = system_font.GetWeight();
 #endif  // BUILDFLAG(IS_WIN)
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // On Linux, LinuxUi is used to query the native toolkit (e.g.
   // GTK) for the default UI font.
   if (auto* linux_ui = ui::LinuxUi::instance()) {
