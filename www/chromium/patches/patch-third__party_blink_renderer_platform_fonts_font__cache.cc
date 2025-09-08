$NetBSD: patch-third__party_blink_renderer_platform_fonts_font__cache.cc,v 1.6 2025/09/08 13:24:31 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/blink/renderer/platform/fonts/font_cache.cc.orig	2025-08-29 18:50:09.000000000 +0000
+++ third_party/blink/renderer/platform/fonts/font_cache.cc
@@ -82,7 +82,7 @@ extern const char kNotoColorEmojiCompat[
 
 SkFontMgr* FontCache::static_font_manager_ = nullptr;
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 float FontCache::device_scale_factor_ = 1.0;
 #endif
 
@@ -136,7 +136,7 @@ const FontPlatformData* FontCache::Syste
     const FontDescription& font_description) {
   const AtomicString& family = FontCache::SystemFontFamily();
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA) || \
-    BUILDFLAG(IS_IOS)
+    BUILDFLAG(IS_IOS) || BUILDFLAG(IS_BSD)
   if (family.empty() || family == font_family_names::kSystemUi)
     return nullptr;
 #else
