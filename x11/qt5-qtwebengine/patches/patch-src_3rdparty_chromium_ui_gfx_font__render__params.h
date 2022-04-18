$NetBSD: patch-src_3rdparty_chromium_ui_gfx_font__render__params.h,v 1.2 2022/04/18 11:18:19 adam Exp $

--- src/3rdparty/chromium/ui/gfx/font_render_params.h.orig	2021-02-19 16:41:59.000000000 +0000
+++ src/3rdparty/chromium/ui/gfx/font_render_params.h
@@ -111,7 +111,7 @@ GFX_EXPORT FontRenderParams GetFontRende
     const FontRenderParamsQuery& query,
     std::string* family_out);
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 // Clears GetFontRenderParams()'s cache. Intended to be called by tests that are
 // changing Fontconfig's configuration.
 GFX_EXPORT void ClearFontRenderParamsCacheForTest();
@@ -121,7 +121,7 @@ GFX_EXPORT void ClearFontRenderParamsCac
 GFX_EXPORT float GetFontRenderParamsDeviceScaleFactor();
 
 #if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_CHROMEOS) || \
-    defined(OS_ANDROID) || defined(OS_FUCHSIA)
+    defined(OS_ANDROID) || defined(OS_FUCHSIA) || defined(OS_BSD)
 // Sets the device scale factor for FontRenderParams to decide
 // if it should enable subpixel positioning.
 GFX_EXPORT void SetFontRenderParamsDeviceScaleFactor(
