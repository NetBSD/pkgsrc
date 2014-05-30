$NetBSD: patch-gfx_gl_GLScreenBuffer.cpp,v 1.1 2014/05/30 03:03:36 pho Exp $

Don't assume cocoa toolkit just because OS_ARCH is Darwin.

--- gfx/gl/GLScreenBuffer.cpp.orig	2014-05-06 22:55:33.000000000 +0000
+++ gfx/gl/GLScreenBuffer.cpp
@@ -16,7 +16,7 @@
 #include "SharedSurfaceGralloc.h"
 #include "nsXULAppAPI.h"
 #endif
-#ifdef XP_MACOSX
+#ifdef MOZ_WIDGET_COCOA
 #include "SharedSurfaceIO.h"
 #endif
 #include "ScopedGLHelpers.h"
@@ -47,7 +47,7 @@ GLScreenBuffer::Create(GLContext* gl,
         factory = new SurfaceFactory_Gralloc(gl, caps);
     }
 #endif
-#ifdef XP_MACOSX
+#ifdef MOZ_WIDGET_COCOA
     /* On OSX, we want an IOSurface factory, and we want one right at the start */
     if (!factory)
     {
