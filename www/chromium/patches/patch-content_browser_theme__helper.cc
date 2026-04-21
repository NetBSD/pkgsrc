$NetBSD: patch-content_browser_theme__helper.cc,v 1.11 2026/04/21 15:21:15 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- content/browser/theme_helper.cc.orig	2026-04-14 23:31:37.000000000 +0200
+++ content/browser/theme_helper.cc
@@ -27,7 +27,7 @@ mojom::UpdateSystemColorInfoParamsPtr Ma
     ui::NativeTheme* native_theme) {
   mojom::UpdateSystemColorInfoParamsPtr params =
       mojom::UpdateSystemColorInfoParams::New();
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   params->accent_color = native_theme->user_color();
 #endif
 
