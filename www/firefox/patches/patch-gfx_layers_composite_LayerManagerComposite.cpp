$NetBSD: patch-gfx_layers_composite_LayerManagerComposite.cpp,v 1.1 2014/05/28 15:11:29 pho Exp $

Don't assume cocoa toolkit just because OS_ARCH is Darwin.

--- gfx/layers/composite/LayerManagerComposite.cpp.orig	2014-05-06 22:55:34.000000000 +0000
+++ gfx/layers/composite/LayerManagerComposite.cpp
@@ -21,7 +21,7 @@
 #include "gfx2DGlue.h"                  // for ToMatrix4x4
 #include "gfx3DMatrix.h"                // for gfx3DMatrix
 #include "gfxPlatform.h"                // for gfxPlatform
-#ifdef XP_MACOSX
+#ifdef MOZ_WIDGET_COCOA
 #include "gfxPlatformMac.h"
 #endif
 #include "gfxRect.h"                    // for gfxRect
@@ -740,7 +740,7 @@ TemporaryRef<DrawTarget>
 LayerManagerComposite::CreateDrawTarget(const IntSize &aSize,
                                         SurfaceFormat aFormat)
 {
-#ifdef XP_MACOSX
+#ifdef MOZ_WIDGET_COCOA
   // We don't want to accelerate if the surface is too small which indicates
   // that it's likely used for an icon/static image. We also don't want to
   // accelerate anything that is above the maximum texture size of weakest gpu.
