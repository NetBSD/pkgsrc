$NetBSD: patch-ui_gfx_font__util.cc,v 1.14 2026/01/19 16:14:22 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- ui/gfx/font_util.cc.orig	2026-01-07 00:50:30.000000000 +0000
+++ ui/gfx/font_util.cc
@@ -6,7 +6,7 @@
 
 #include "build/build_config.h"
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include <fontconfig/fontconfig.h>
 #include "ui/gfx/linux/fontconfig_util.h"
 #endif
@@ -24,7 +24,7 @@ void InitializeFonts() {
   // background (resources have not yet been granted to cast) since it prevents
   // the long delay the user would have seen on first rendering.
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // Early initialize FontConfig.
   InitializeGlobalFontConfigAsync();
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
