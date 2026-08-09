$NetBSD: patch-ui_gfx_render__text__api__fuzzer.cc,v 1.24 2026/08/09 06:31:25 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- ui/gfx/render_text_api_fuzzer.cc.orig	2026-08-05 20:17:42.000000000 +0000
+++ ui/gfx/render_text_api_fuzzer.cc
@@ -24,7 +24,7 @@
 #include "base/test/test_support_android.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "third_party/test_fonts/fontconfig/fontconfig_util_linux.h"
 #endif
 
@@ -59,7 +59,7 @@ struct Environment {
 
     CHECK(base::i18n::InitializeICU());
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     test_fonts::SetUpFontconfig();
 #endif
     gfx::InitializeFonts();
