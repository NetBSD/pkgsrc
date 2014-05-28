$NetBSD: patch-gfx_layers_basic_BasicImages.cpp,v 1.1 2014/05/28 15:11:29 pho Exp $

Don't assume cocoa toolkit just because OS_ARCH is Darwin.

--- gfx/layers/basic/BasicImages.cpp.orig	2014-05-06 22:55:33.000000000 +0000
+++ gfx/layers/basic/BasicImages.cpp
@@ -22,7 +22,7 @@
 #include "mozilla/gfx/Point.h"          // for IntSize
 #include "gfx2DGlue.h"
 #include "YCbCrUtils.h"                 // for YCbCr conversions
-#ifdef XP_MACOSX
+#ifdef MOZ_WIDGET_COCOA
 #include "gfxQuartzImageSurface.h"
 #endif
 
@@ -154,7 +154,7 @@ BasicPlanarYCbCrImage::DeprecatedGetAsSu
   imgSurface->SetData(&imageSurfaceDataKey, mDecodedBuffer.forget(), DestroyBuffer);
 
   nsRefPtr<gfxASurface> result = imgSurface.get();
-#if defined(XP_MACOSX)
+#if defined(MOZ_WIDGET_COCOA)
   nsRefPtr<gfxQuartzImageSurface> quartzSurface =
     new gfxQuartzImageSurface(imgSurface);
   if (quartzSurface) {
