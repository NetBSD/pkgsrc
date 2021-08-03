$NetBSD: patch-src_3rdparty_chromium_third__party_blink_renderer_platform_fonts_font__cache.cc,v 1.1 2021/08/03 21:04:35 markd Exp $

--- src/3rdparty/chromium/third_party/blink/renderer/platform/fonts/font_cache.cc.orig	2020-07-15 18:56:03.000000000 +0000
+++ src/3rdparty/chromium/third_party/blink/renderer/platform/fonts/font_cache.cc
@@ -80,7 +80,7 @@ const char kColorEmojiLocale[] = "und-Zs
 
 SkFontMgr* FontCache::static_font_manager_ = nullptr;
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 float FontCache::device_scale_factor_ = 1.0;
 #endif
 
@@ -120,7 +120,7 @@ FontCache::FontCache()
 FontPlatformData* FontCache::SystemFontPlatformData(
     const FontDescription& font_description) {
   const AtomicString& family = FontCache::SystemFontFamily();
-#if defined(OS_LINUX) || defined(OS_FUCHSIA)
+#if defined(OS_LINUX) || defined(OS_FUCHSIA) || defined(OS_BSD)
   if (family.IsEmpty() || family == font_family_names::kSystemUi)
     return nullptr;
 #else
