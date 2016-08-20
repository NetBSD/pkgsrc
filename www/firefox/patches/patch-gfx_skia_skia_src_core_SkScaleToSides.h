$NetBSD: patch-gfx_skia_skia_src_core_SkScaleToSides.h,v 1.1 2016/08/20 11:17:32 ryoon Exp $

--- gfx/skia/skia/src/core/SkScaleToSides.h.orig	2016-06-01 04:11:44.000000000 +0000
+++ gfx/skia/skia/src/core/SkScaleToSides.h
@@ -46,10 +46,8 @@ public:
 
             // If newMaxRadius forces the total over the limit, then it needs to be
             // reduced by one ULP to be less than limit - newMinRadius.
-            // Note: nexttowardf is a c99 call and should be std::nexttoward, but this is not
-            // implemented in the ARM compiler.
             if ((double)newMaxRadius + (double)newMinRadius > limit) {
-                newMaxRadius = nexttowardf(newMaxRadius, 0.0);
+                newMaxRadius = nextafterf(newMaxRadius, 0.0);
             }
             *maxRadius = newMaxRadius;
         }
