$NetBSD: patch-content_browser_theme__helper.cc,v 1.17 2026/08/09 06:31:17 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- content/browser/theme_helper.cc.orig	2026-08-05 20:17:42.000000000 +0000
+++ content/browser/theme_helper.cc
@@ -27,7 +27,7 @@ mojom::UpdateSystemColorInfoParamsPtr Ma
     ui::NativeTheme* native_theme) {
   mojom::UpdateSystemColorInfoParamsPtr params =
       mojom::UpdateSystemColorInfoParams::New();
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   params->accent_color = native_theme->user_color();
 #endif
 
