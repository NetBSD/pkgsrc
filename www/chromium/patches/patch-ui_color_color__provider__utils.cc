$NetBSD: patch-ui_color_color__provider__utils.cc,v 1.2 2025/05/16 16:08:34 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- ui/color/color_provider_utils.cc.orig	2025-05-05 19:21:24.000000000 +0000
+++ ui/color/color_provider_utils.cc
@@ -191,7 +191,7 @@ std::string_view SystemThemeName(ui::Sys
   switch (system_theme) {
     case ui::SystemTheme::kDefault:
       return "kDefault";
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     case ui::SystemTheme::kGtk:
       return "kGtk";
     case ui::SystemTheme::kQt:
