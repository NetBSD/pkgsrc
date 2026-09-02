$NetBSD: patch-ui_gfx_font__util.cc,v 1.25 2026/09/02 13:13:39 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- ui/gfx/font_util.cc.orig	2026-08-31 22:47:51.000000000 +0000
+++ ui/gfx/font_util.cc
@@ -7,7 +7,7 @@
 #include "build/build_config.h"
 #include "skia/ext/font_utils.h"
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include <fontconfig/fontconfig.h>
 #include "ui/gfx/linux/fontconfig_util.h"
 #endif
@@ -25,7 +25,7 @@ void InitializeFonts() {
   // background (resources have not yet been granted to cast) since it prevents
   // the long delay the user would have seen on first rendering.
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // Early initialize FontConfig.
   InitializeGlobalFontConfigAsync();
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
