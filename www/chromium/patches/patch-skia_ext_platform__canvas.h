$NetBSD: patch-skia_ext_platform__canvas.h,v 1.1 2025/02/06 09:58:21 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- skia/ext/platform_canvas.h.orig	2024-12-17 17:58:49.000000000 +0000
+++ skia/ext/platform_canvas.h
@@ -58,7 +58,7 @@ SK_API HDC GetNativeDrawingContext(SkCan
 
 #elif defined(__linux__) || defined(__FreeBSD__) || defined(__OpenBSD__) || \
     defined(__sun) || defined(ANDROID) || defined(__APPLE__) ||             \
-    defined(__Fuchsia__)
+    defined(__Fuchsia__) || defined(__NetBSD__)
 // Construct a canvas from the given memory region. The memory is not cleared
 // first. @data must be, at least, @height * StrideForWidth(@width) bytes.
 SK_API std::unique_ptr<SkCanvas> CreatePlatformCanvasWithPixels(
