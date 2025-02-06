$NetBSD: patch-ui_gfx_font__render__params__linux.cc,v 1.1 2025/02/06 09:58:32 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- ui/gfx/font_render_params_linux.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ ui/gfx/font_render_params_linux.cc
@@ -25,7 +25,7 @@
 #include "ui/gfx/linux/fontconfig_util.h"
 #include "ui/gfx/switches.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "ui/linux/linux_ui.h"
 #endif
 
@@ -212,7 +212,7 @@ FontRenderParams GetFontRenderParams(con
 
   // Start with the delegate's settings, but let Fontconfig have the final say.
   FontRenderParams params;
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (auto* linux_ui = ui::LinuxUi::instance()) {
     params = linux_ui->GetDefaultFontRenderParams();
   }
