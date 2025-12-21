$NetBSD: patch-src_3rdparty_chromium_third__party_blink_renderer_core_exported_web__view__impl.cc,v 1.1 2025/12/21 09:38:39 markd Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/third_party/blink/renderer/core/exported/web_view_impl.cc.orig	2025-10-02 00:36:39.000000000 +0000
+++ src/3rdparty/chromium/third_party/blink/renderer/core/exported/web_view_impl.cc
@@ -429,7 +429,7 @@ void RecordPrerenderActivationSignalDela
 #if !BUILDFLAG(IS_MAC) && !BUILDFLAG(IS_WIN)
 SkFontHinting RendererPreferencesToSkiaHinting(
     const blink::RendererPreferences& prefs) {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (!prefs.should_antialias_text) {
     // When anti-aliasing is off, GTK maps all non-zero hinting settings to
     // 'Normal' hinting so we do the same. Otherwise, folks who have 'Slight'
@@ -3430,7 +3430,7 @@ void WebViewImpl::UpdateFontRenderingFro
       gfx::FontRenderParams::SUBPIXEL_RENDERING_NONE);
   WebFontRenderStyle::SetSubpixelPositioning(
       renderer_preferences_.use_subpixel_positioning);
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (!renderer_preferences_.system_font_family_name.empty()) {
     WebFontRenderStyle::SetSystemFontFamily(blink::WebString::FromUTF8(
         renderer_preferences_.system_font_family_name));
