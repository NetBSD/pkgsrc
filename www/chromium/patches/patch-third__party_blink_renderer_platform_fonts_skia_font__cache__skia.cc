$NetBSD: patch-third__party_blink_renderer_platform_fonts_skia_font__cache__skia.cc,v 1.18 2026/04/21 15:21:21 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/blink/renderer/platform/fonts/skia/font_cache_skia.cc.orig	2026-04-14 23:31:37.000000000 +0200
+++ third_party/blink/renderer/platform/fonts/skia/font_cache_skia.cc
@@ -304,7 +304,7 @@ const FontPlatformData* FontCache::Creat
   std::string name;
 
   sk_sp<SkTypeface> typeface;
-#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   bool noto_color_emoji_from_gmscore = false;
 #if BUILDFLAG(IS_ANDROID)
   // Use the unique local matching pathway for fetching Noto Color Emoji Compat
