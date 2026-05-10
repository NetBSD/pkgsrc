$NetBSD: patch-ui_gfx_font__render__params__linux.cc,v 1.19 2026/05/10 15:30:08 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- ui/gfx/font_render_params_linux.cc.orig	2026-04-28 23:05:57.000000000 +0200
+++ ui/gfx/font_render_params_linux.cc
@@ -24,7 +24,7 @@
 #include "ui/gfx/linux/fontconfig_util.h"
 #include "ui/gfx/switches.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "ui/linux/linux_ui.h"
 #endif
 
@@ -233,7 +233,7 @@ FontRenderParams GetFontRenderParams(con
 
   // Start with the delegate's settings, but let Fontconfig have the final say.
   FontRenderParams params;
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (auto* linux_ui = ui::LinuxUi::instance()) {
     params = linux_ui->GetDefaultFontRenderParams();
   }
