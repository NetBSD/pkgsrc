$NetBSD: patch-src_3rdparty_chromium_third__party_blink_renderer_platform_fonts_skia_font__cache__skia.cc,v 1.1 2021/08/03 21:04:35 markd Exp $

--- src/3rdparty/chromium/third_party/blink/renderer/platform/fonts/skia/font_cache_skia.cc.orig	2020-07-15 18:56:03.000000000 +0000
+++ src/3rdparty/chromium/third_party/blink/renderer/platform/fonts/skia/font_cache_skia.cc
@@ -61,7 +61,7 @@ AtomicString ToAtomicString(const SkStri
   return AtomicString::FromUTF8(str.c_str(), str.size());
 }
 
-#if defined(OS_ANDROID) || defined(OS_LINUX)
+#if defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_BSD)
 // This function is called on android or when we are emulating android fonts on
 // linux and the embedder has overriden the default fontManager with
 // WebFontRendering::setSkiaFontMgr.
@@ -229,7 +229,7 @@ sk_sp<SkTypeface> FontCache::CreateTypef
   }
 #endif
 
-#if defined(OS_LINUX) || defined(OS_WIN)
+#if defined(OS_LINUX) || defined(OS_WIN) || defined(OS_BSD)
   // On linux if the fontManager has been overridden then we should be calling
   // the embedder provided font Manager rather than calling
   // SkTypeface::CreateFromName which may redirect the call to the default font
@@ -263,7 +263,7 @@ std::unique_ptr<FontPlatformData> FontCa
   std::string name;
 
   sk_sp<SkTypeface> typeface;
-#if defined(OS_ANDROID) || defined(OS_LINUX)
+#if defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_BSD)
   if (alternate_name == AlternateFontName::kLocalUniqueFace &&
       RuntimeEnabledFeatures::FontSrcLocalMatchingEnabled()) {
     typeface = CreateTypefaceFromUniqueName(creation_params);
