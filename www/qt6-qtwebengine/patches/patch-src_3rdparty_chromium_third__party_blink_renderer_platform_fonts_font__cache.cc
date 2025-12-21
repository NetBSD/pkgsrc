$NetBSD: patch-src_3rdparty_chromium_third__party_blink_renderer_platform_fonts_font__cache.cc,v 1.1 2025/12/21 09:38:40 markd Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/third_party/blink/renderer/platform/fonts/font_cache.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ src/3rdparty/chromium/third_party/blink/renderer/platform/fonts/font_cache.cc
@@ -81,7 +81,7 @@ extern const char kNotoColorEmojiCompat[
 
 SkFontMgr* FontCache::static_font_manager_ = nullptr;
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 float FontCache::device_scale_factor_ = 1.0;
 #endif
 
@@ -132,7 +132,7 @@ const FontPlatformData* FontCache::Syste
     const FontDescription& font_description) {
   const AtomicString& family = FontCache::SystemFontFamily();
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA) || \
-    BUILDFLAG(IS_IOS)
+    BUILDFLAG(IS_IOS) || BUILDFLAG(IS_BSD)
   if (family.empty() || family == font_family_names::kSystemUi)
     return nullptr;
 #else
