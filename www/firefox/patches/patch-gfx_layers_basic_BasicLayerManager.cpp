$NetBSD: patch-gfx_layers_basic_BasicLayerManager.cpp,v 1.2 2015/04/05 12:54:11 ryoon Exp $

Part of the patch in https://bugzilla.mozilla.org/show_bug.cgi?id=1105087
(sligthly modified to fix a compile error: PixmanTransform -> DrawTransform)

diff --git a/gfx/layers/basic/BasicLayerManager.cpp b/gfx/layers/basic/BasicLayerManager.cpp
--- gfx/layers/basic/BasicLayerManager.cpp.orig	2015-03-27 02:20:33.000000000 +0000
+++ gfx/layers/basic/BasicLayerManager.cpp
@@ -46,8 +46,13 @@
 #include "nsRect.h"                     // for nsIntRect
 #include "nsRegion.h"                   // for nsIntRegion, etc
 #include "nsTArray.h"                   // for nsAutoTArray
+#if MOZ_ENABLE_SKIA
 #include "skia/SkCanvas.h"              // for SkCanvas
 #include "skia/SkBitmapDevice.h"        // for SkBitmapDevice
+#else
+#define PIXMAN_DONT_DEFINE_STDINT
+#include "pixman.h"                     // for pixman_f_transform, etc
+#endif
 class nsIWidget;
 
 namespace mozilla {
@@ -606,6 +611,7 @@ BasicLayerManager::SetRoot(Layer* aLayer
   mRoot = aLayer;
 }
 
+#if MOZ_ENABLE_SKIA
 static SkMatrix
 BasicLayerManager_Matrix3DToSkia(const gfx3DMatrix& aMatrix)
 {
@@ -624,7 +630,7 @@ BasicLayerManager_Matrix3DToSkia(const g
 }
 
 static void
-SkiaTransform(const gfxImageSurface* aDest,
+DrawTransform(const gfxImageSurface* aDest,
               RefPtr<DataSourceSurface> aSrc,
               const gfx3DMatrix& aTransform,
               gfxPoint aDestOffset)
@@ -663,6 +669,79 @@ SkiaTransform(const gfxImageSurface* aDe
   SkRect destRect = SkRect::MakeXYWH(0, 0, srcSize.width, srcSize.height);
   destCanvas.drawBitmapRectToRect(src, nullptr, destRect, &paint);
 }
+#else
+// See bugs 1097776 and 1105087.
+static pixman_transform
+BasicLayerManager_Matrix3DToPixman(const gfx3DMatrix& aMatrix)
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
+DrawTransform(const gfxImageSurface* aDest,
+                RefPtr<DataSourceSurface> aSrc,
+                const gfx3DMatrix& aTransform,
+                gfxPoint aDestOffset)
+{
+  IntSize destSize = ToIntSize(aDest->GetSize());
+  pixman_image_t* dest = pixman_image_create_bits(aDest->Format() == gfxImageFormat::ARGB32 ? PIXMAN_a8r8g8b8 : PIXMAN_x8r8g8b8,
+                                                  destSize.width,
+                                                  destSize.height,
+                                                  (uint32_t*)aDest->Data(),
+                                                  aDest->Stride());
+
+  IntSize srcSize = aSrc->GetSize();
+  pixman_image_t* src = pixman_image_create_bits(aSrc->GetFormat() == SurfaceFormat::B8G8R8A8 ? PIXMAN_a8r8g8b8 : PIXMAN_x8r8g8b8,
+                                                 srcSize.width,
+                                                 srcSize.height,
+                                                 (uint32_t*)aSrc->GetData(),
+                                                 aSrc->Stride());
+
+  NS_ABORT_IF_FALSE(src && dest, "Failed to create pixman images?");
+
+  pixman_transform pixTransform = BasicLayerManager_Matrix3DToPixman(aTransform);
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
 
 /**
  * Transform a surface using a gfx3DMatrix and blit to the destination if
@@ -704,7 +783,7 @@ Transform3D(RefPtr<SourceSurface> aSourc
   gfx3DMatrix translation = gfx3DMatrix::Translation(aBounds.x, aBounds.y, 0);
 
   // Transform the content and offset it such that the content begins at the origin.
-  SkiaTransform(destImage, aSource->GetDataSurface(), translation * aTransform, offset);
+  DrawTransform(destImage, aSource->GetDataSurface(), translation * aTransform, offset);
 
   // If we haven't actually drawn to aDest then return our temporary image so
   // that the caller can do this.
