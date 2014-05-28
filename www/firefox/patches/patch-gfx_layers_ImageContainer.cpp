$NetBSD: patch-gfx_layers_ImageContainer.cpp,v 1.1 2014/05/28 15:11:29 pho Exp $

Don't assume cocoa toolkit just because OS_ARCH is Darwin.

--- gfx/layers/ImageContainer.cpp.orig	2014-05-06 22:55:33.000000000 +0000
+++ gfx/layers/ImageContainer.cpp
@@ -23,7 +23,7 @@
 #endif
 #include "gfx2DGlue.h"
 
-#ifdef XP_MACOSX
+#ifdef MOZ_WIDGET_COCOA
 #include "mozilla/gfx/QuartzSupport.h"
 #include "MacIOSurfaceImage.h"
 #endif
@@ -81,7 +81,7 @@ ImageFactory::CreateImage(ImageFormat aF
     img = new SharedTextureImage();
     return img.forget();
   }
-#ifdef XP_MACOSX
+#ifdef MOZ_WIDGET_COCOA
   if (aFormat == ImageFormat::MAC_IOSURFACE) {
     img = new MacIOSurfaceImage();
     return img.forget();
