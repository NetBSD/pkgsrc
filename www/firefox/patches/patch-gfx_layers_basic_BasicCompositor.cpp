$NetBSD: patch-gfx_layers_basic_BasicCompositor.cpp,v 1.2 2015/04/05 12:54:11 ryoon Exp $

Part of the patch in https://bugzilla.mozilla.org/show_bug.cgi?id=1105087

diff -git a/gfx/layers/basic/BasicCompositor.cpp b/gfx/layers/basic/BasicCompositor.cpp
--- gfx/layers/basic/BasicCompositor.cpp.orig	2015-03-27 02:20:33.000000000 +0000
+++ gfx/layers/basic/BasicCompositor.cpp
@@ -17,8 +17,13 @@
 #include <algorithm>
 #include "ImageContainer.h"
 #include "gfxPrefs.h"
+#if MOZ_ENABLE_SKIA
 #include "skia/SkCanvas.h"              // for SkCanvas
 #include "skia/SkBitmapDevice.h"        // for SkBitmapDevice
+#else
+#define PIXMAN_DONT_DEFINE_STDINT
+#include "pixman.h"                     // for pixman_f_transform, etc
+#endif
 
 namespace mozilla {
 using namespace mozilla::gfx;
@@ -177,6 +182,7 @@ DrawSurfaceWithTextureCoords(DrawTarget 
                    mode, aMask, aMaskTransform, &matrix);
 }
 
+#if MOZ_ENABLE_SKIA
 static SkMatrix
 Matrix3DToSkia(const gfx3DMatrix& aMatrix)
 {
@@ -195,7 +201,7 @@ Matrix3DToSkia(const gfx3DMatrix& aMatri
 }
 
 static void
-SkiaTransform(DataSourceSurface* aDest,
+DrawTransform(DataSourceSurface* aDest,
               DataSourceSurface* aSource,
               const gfx3DMatrix& aTransform,
               const Point& aDestOffset)
@@ -234,6 +240,80 @@ SkiaTransform(DataSourceSurface* aDest,
   SkRect destRect = SkRect::MakeXYWH(0, 0, srcSize.width, srcSize.height);
   destCanvas.drawBitmapRectToRect(src, nullptr, destRect, &paint);
 }
+#else
+// Cairo must rely on a less precise method if Skia is not available.
+// See bugs 1105087 and 1097776.
+static pixman_transform
+Matrix3DToPixman(const gfx3DMatrix& aMatrix)
+{
+  pixman_f_transform transform;
+
+  transform.m[0][0] = aMatrix._11;
+  transform.m[0][1] = aMatrix._21;
+  transform.m[0][2] = aMatrix._41;
+  transform.m[1][0] = aMatrix._12;
+  transform.m[1][1] = aMatrix._22;
+  transform.m[1][2] = aMatrix._42;
+  transform.m[2][0] = aMatrix._14;
+  transform.m[2][1] = aMatrix._24;
+  transform.m[2][2] = aMatrix._44;
+
+  pixman_transform result;
+  pixman_transform_from_pixman_f_transform(&result, &transform);
+
+  return result;
+}
+
+static void
+DrawTransform(DataSourceSurface* aDest,
+              DataSourceSurface* aSource,
+              const gfx3DMatrix& aTransform,
+              const Point& aDestOffset)
+{
+  IntSize destSize = aDest->GetSize();
+  pixman_image_t* dest = pixman_image_create_bits(PIXMAN_a8r8g8b8,
+                                                  destSize.width,
+                                                  destSize.height,
+                                                  (uint32_t*)aDest->GetData(),
+                                                  aDest->Stride());
+
+  IntSize srcSize = aSource->GetSize();
+  pixman_image_t* src = pixman_image_create_bits(PIXMAN_a8r8g8b8,
+                                                 srcSize.width,
+                                                 srcSize.height,
+                                                 (uint32_t*)aSource->GetData(),
+                                                 aSource->Stride());
+
+  NS_ABORT_IF_FALSE(src && dest, "Failed to create pixman images?");
+
+  pixman_transform pixTransform = Matrix3DToPixman(aTransform);
+  pixman_transform pixTransformInverted;
+
+  // If the transform is singular then nothing would be drawn anyway, return here
+  if (!pixman_transform_invert(&pixTransformInverted, &pixTransform)) {
+    pixman_image_unref(dest);
+    pixman_image_unref(src);
+    return;
+  }
+  pixman_image_set_transform(src, &pixTransformInverted);
+
+  pixman_image_composite32(PIXMAN_OP_SRC,
+                           src,
+                           nullptr,
+                           dest,
+                           aDestOffset.x,
+                           aDestOffset.y,
+                           0,
+                           0,
+                           0,
+                           0,
+                           destSize.width,
+                           destSize.height);
+
+  pixman_image_unref(dest);
+  pixman_image_unref(src);
+}
+#endif
 
 static inline IntRect
 RoundOut(Rect r)
@@ -378,7 +458,7 @@ BasicCompositor::DrawQuad(const gfx::Rec
       return;
     }
 
-    SkiaTransform(temp, source, new3DTransform, transformBounds.TopLeft());
+    DrawTransform(temp, source, new3DTransform, transformBounds.TopLeft());
 
     transformBounds.MoveTo(0, 0);
     buffer->DrawSurface(temp, transformBounds, transformBounds);
