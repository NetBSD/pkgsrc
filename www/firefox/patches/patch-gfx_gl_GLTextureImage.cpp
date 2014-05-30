$NetBSD: patch-gfx_gl_GLTextureImage.cpp,v 1.1 2014/05/30 03:03:36 pho Exp $

Don't assume cocoa toolkit just because OS_ARCH is Darwin.

--- gfx/gl/GLTextureImage.cpp.orig	2014-05-06 22:55:33.000000000 +0000
+++ gfx/gl/GLTextureImage.cpp
@@ -13,7 +13,7 @@
 #include "GLUploadHelpers.h"
 
 #include "TextureImageEGL.h"
-#ifdef XP_MACOSX
+#ifdef MOZ_WIDGET_COCOA
 #include "TextureImageCGL.h"
 #endif
 
@@ -29,7 +29,7 @@ CreateTextureImage(GLContext* gl,
                    TextureImage::ImageFormat aImageFormat)
 {
     switch (gl->GetContextType()) {
-#ifdef XP_MACOSX
+#ifdef MOZ_WIDGET_COCOA
         case GLContextType::CGL:
             return CreateTextureImageCGL(gl, aSize, aContentType, aWrapMode, aFlags, aImageFormat);
 #endif
@@ -49,7 +49,7 @@ TileGenFunc(GLContext* gl,
             TextureImage::ImageFormat aImageFormat)
 {
     switch (gl->GetContextType()) {
-#ifdef XP_MACOSX
+#ifdef MOZ_WIDGET_COCOA
         case GLContextType::CGL:
             return TileGenFuncCGL(gl, aSize, aContentType, aFlags, aImageFormat);
 #endif
