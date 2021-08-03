$NetBSD: patch-src_3rdparty_chromium_skia_ext_platform__canvas.h,v 1.1 2021/08/03 21:04:35 markd Exp $

--- src/3rdparty/chromium/skia/ext/platform_canvas.h.orig	2020-07-15 18:56:01.000000000 +0000
+++ src/3rdparty/chromium/skia/ext/platform_canvas.h
@@ -58,7 +58,7 @@ SK_API HDC GetNativeDrawingContext(SkCan
 
 #elif defined(__linux__) || defined(__FreeBSD__) || defined(__OpenBSD__) || \
     defined(__sun) || defined(ANDROID) || defined(__APPLE__) ||             \
-    defined(__Fuchsia__)
+    defined(__Fuchsia__) || defined(__NetBSD__)
 // Construct a canvas from the given memory region. The memory is not cleared
 // first. @data must be, at least, @height * StrideForWidth(@width) bytes.
 SK_API std::unique_ptr<SkCanvas> CreatePlatformCanvasWithPixels(
