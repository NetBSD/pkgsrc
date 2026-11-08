$NetBSD: patch-ui_gfx_font__util.cc,v 1.32 2026/11/08 15:39:13 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- ui/gfx/font_util.cc.orig	2026-11-02 23:22:33.000000000 +0000
+++ ui/gfx/font_util.cc
@@ -7,7 +7,7 @@
 #include "build/build_config.h"
 #include "skia/ext/font_utils.h"
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include <fontconfig/fontconfig.h>
 
 #include "base/check.h"
@@ -29,7 +29,7 @@ void InitializeFonts() {
   // background (resources have not yet been granted to cast) since it prevents
   // the long delay the user would have seen on first rendering.
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   if (base::FeatureList::IsEnabled(features::kAsyncFontconfigInitialization)) {
     // Early initialize FontConfig.
     InitializeGlobalFontConfigAsync();
