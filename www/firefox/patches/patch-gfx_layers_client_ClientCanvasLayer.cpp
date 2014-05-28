$NetBSD: patch-gfx_layers_client_ClientCanvasLayer.cpp,v 1.1 2014/05/28 15:11:29 pho Exp $

Don't assume cocoa toolkit just because OS_ARCH is Darwin.

--- gfx/layers/client/ClientCanvasLayer.cpp.orig	2014-05-06 22:55:33.000000000 +0000
+++ gfx/layers/client/ClientCanvasLayer.cpp
@@ -22,7 +22,7 @@
 #ifdef MOZ_WIDGET_GONK
 #include "SharedSurfaceGralloc.h"
 #endif
-#ifdef XP_MACOSX
+#ifdef MOZ_WIDGET_COCOA
 #include "SharedSurfaceIO.h"
 #endif
 
@@ -65,7 +65,7 @@ ClientCanvasLayer::Initialize(const Data
         } else {
           // [Basic Layers, OMTC] WebGL layer init.
           // Well, this *should* work...
-#ifdef XP_MACOSX
+#ifdef MOZ_WIDGET_COCOA
           factory = new SurfaceFactory_IOSurface(mGLContext, screen->Caps());
 #else
           factory = new SurfaceFactory_GLTexture(mGLContext, nullptr, screen->Caps());
