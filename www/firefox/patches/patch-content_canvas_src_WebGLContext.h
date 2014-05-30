$NetBSD: patch-content_canvas_src_WebGLContext.h,v 1.1 2014/05/30 03:03:36 pho Exp $

Don't assume cocoa toolkit just because OS_ARCH is Darwin.

--- content/canvas/src/WebGLContext.h.orig	2014-05-06 22:55:17.000000000 +0000
+++ content/canvas/src/WebGLContext.h
@@ -30,7 +30,7 @@
 #include "mozilla/Scoped.h"
 #include "mozilla/gfx/2D.h"
 
-#ifdef XP_MACOSX
+#ifdef MOZ_WIDGET_COCOA
 #include "ForceDiscreteGPUHelperCGL.h"
 #endif
 
@@ -1173,7 +1173,7 @@ protected:
 
     void ReattachTextureToAnyFramebufferToWorkAroundBugs(WebGLTexture *tex, GLint level);
 
-#ifdef XP_MACOSX
+#ifdef MOZ_WIDGET_COCOA
     // see bug 713305. This RAII helper guarantees that we're on the discrete GPU, during its lifetime
     // Debouncing note: we don't want to switch GPUs too frequently, so try to not create and destroy
     // these objects at high frequency. Having WebGLContext's hold one such object seems fine,
