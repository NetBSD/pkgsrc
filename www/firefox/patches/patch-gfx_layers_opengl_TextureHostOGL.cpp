$NetBSD: patch-gfx_layers_opengl_TextureHostOGL.cpp,v 1.1 2014/05/28 15:11:29 pho Exp $

Don't assume cocoa toolkit just because OS_ARCH is Darwin.

--- gfx/layers/opengl/TextureHostOGL.cpp.orig	2014-05-06 22:55:34.000000000 +0000
+++ gfx/layers/opengl/TextureHostOGL.cpp
@@ -32,7 +32,7 @@
 #include "nsRegion.h"                   // for nsIntRegion
 #include "GfxTexturesReporter.h"        // for GfxTexturesReporter
 #include "GLBlitTextureImageHelper.h"
-#ifdef XP_MACOSX
+#ifdef MOZ_WIDGET_COCOA
 #include "SharedSurfaceIO.h"
 #include "mozilla/layers/MacIOSurfaceTextureHostOGL.h"
 #endif
@@ -113,7 +113,7 @@ CreateTextureHostOGL(const SurfaceDescri
       result = new StreamTextureHostOGL(aFlags, desc);
       break;
     }
-#ifdef XP_MACOSX
+#ifdef MOZ_WIDGET_COCOA
     case SurfaceDescriptor::TSurfaceDescriptorMacIOSurface: {
       const SurfaceDescriptorMacIOSurface& desc =
         aDesc.get_SurfaceDescriptorMacIOSurface();
@@ -519,7 +519,7 @@ StreamTextureSourceOGL::RetrieveTextureF
       }
       break;
     }
-#ifdef XP_MACOSX
+#ifdef MOZ_WIDGET_COCOA
     case SharedSurfaceType::IOSurface: {
       SharedSurface_IOSurface* glTexSurf = SharedSurface_IOSurface::Cast(sharedSurf);
       mTextureHandle = glTexSurf->Texture();
@@ -991,7 +991,7 @@ SurfaceStreamHostOGL::Lock()
       }
       break;
     }
-#ifdef XP_MACOSX
+#ifdef MOZ_WIDGET_COCOA
     case SharedSurfaceType::IOSurface: {
       SharedSurface_IOSurface* glTexSurf = SharedSurface_IOSurface::Cast(sharedSurf);
       mTextureHandle = glTexSurf->Texture();
