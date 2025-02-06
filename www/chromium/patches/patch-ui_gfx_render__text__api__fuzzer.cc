$NetBSD: patch-ui_gfx_render__text__api__fuzzer.cc,v 1.1 2025/02/06 09:58:32 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- ui/gfx/render_text_api_fuzzer.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ ui/gfx/render_text_api_fuzzer.cc
@@ -20,7 +20,7 @@
 #include "ui/gfx/font_util.h"
 #include "ui/gfx/render_text.h"
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "third_party/test_fonts/fontconfig/fontconfig_util_linux.h"
 #endif
 
@@ -47,7 +47,7 @@ struct Environment {
 
     CHECK(base::i18n::InitializeICU());
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     test_fonts::SetUpFontconfig();
 #endif
     gfx::InitializeFonts();
