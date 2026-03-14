$NetBSD: patch-third__party_blink_renderer_platform_fonts_font__cache.cc,v 1.16 2026/03/14 12:40:41 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/blink/renderer/platform/fonts/font_cache.cc.orig	2026-03-11 22:12:25.000000000 +0000
+++ third_party/blink/renderer/platform/fonts/font_cache.cc
@@ -80,7 +80,7 @@ const char kMonoEmojiLocale[] = "und-Zsy
 extern const char kNotoColorEmojiCompat[] = "Noto Color Emoji Compat";
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 float FontCache::device_scale_factor_ = 1.0;
 #endif
 
@@ -112,7 +112,7 @@ const FontPlatformData* FontCache::Syste
     const FontDescription& font_description) {
   const AtomicString& family = FontCache::SystemFontFamily();
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA) || \
-    BUILDFLAG(IS_IOS)
+    BUILDFLAG(IS_IOS) || BUILDFLAG(IS_BSD)
   if (family.empty() || family == font_family_names::kSystemUi)
     return nullptr;
 #else
