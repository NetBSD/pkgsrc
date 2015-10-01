$NetBSD: patch-fb_fbtrap.c,v 1.1 2015/10/01 12:55:09 tnn Exp $

http://cgit.freedesktop.org/~jeremyhu/xserver/log/?h=server-1.17-apple

--- fb/fbtrap.c.orig	2014-10-23 22:11:20.000000000 +0000
+++ fb/fbtrap.c
@@ -36,13 +36,12 @@ fbAddTraps(PicturePtr pPicture,
            INT16 x_off, INT16 y_off, int ntrap, xTrap * traps)
 {
     pixman_image_t *image;
-    int dst_xoff, dst_yoff;
 
-    if (!(image = image_from_pict(pPicture, FALSE, &dst_xoff, &dst_yoff)))
+    if (!(image = image_from_pict (pPicture, FALSE)))
         return;
 
-    pixman_add_traps(image, x_off + dst_xoff, y_off + dst_yoff,
-                     ntrap, (pixman_trap_t *) traps);
+    pixman_add_traps(image, x_off, y_off,
+                     ntrap, (pixman_trap_t *)traps);
 
     free_pixman_pict(pPicture, image);
 }
@@ -52,13 +51,12 @@ fbRasterizeTrapezoid(PicturePtr pPicture
                      xTrapezoid * trap, int x_off, int y_off)
 {
     pixman_image_t *image;
-    int dst_xoff, dst_yoff;
 
-    if (!(image = image_from_pict(pPicture, FALSE, &dst_xoff, &dst_yoff)))
+    if (!(image = image_from_pict (pPicture, FALSE)))
         return;
 
-    pixman_rasterize_trapezoid(image, (pixman_trapezoid_t *) trap,
-                               x_off + dst_xoff, y_off + dst_yoff);
+    pixman_rasterize_trapezoid(image, (pixman_trapezoid_t *)trap,
+                               x_off, y_off);
 
     free_pixman_pict(pPicture, image);
 }
@@ -68,14 +66,12 @@ fbAddTriangles(PicturePtr pPicture,
                INT16 x_off, INT16 y_off, int ntri, xTriangle * tris)
 {
     pixman_image_t *image;
-    int dst_xoff, dst_yoff;
 
-    if (!(image = image_from_pict(pPicture, FALSE, &dst_xoff, &dst_yoff)))
+    if (!(image = image_from_pict (pPicture, FALSE)))
         return;
 
-    pixman_add_triangles(image,
-                         dst_xoff + x_off, dst_yoff + y_off,
-                         ntri, (pixman_triangle_t *) tris);
+    pixman_add_triangles(image, x_off, y_off, ntri,
+                         (pixman_triangle_t *)tris);
 
     free_pixman_pict(pPicture, image);
 }
@@ -98,13 +94,11 @@ fbShapes(CompositeShapesFunc composite,
          int16_t ySrc, int nshapes, int shape_size, const uint8_t * shapes)
 {
     pixman_image_t *src, *dst;
-    int src_xoff, src_yoff;
-    int dst_xoff, dst_yoff;
 
     miCompositeSourceValidate(pSrc);
 
-    src = image_from_pict(pSrc, FALSE, &src_xoff, &src_yoff);
-    dst = image_from_pict(pDst, TRUE, &dst_xoff, &dst_yoff);
+    src = image_from_pict(pSrc, FALSE);
+    dst = image_from_pict(pDst, TRUE);
 
     if (src && dst) {
         pixman_format_code_t format;
@@ -121,9 +115,8 @@ fbShapes(CompositeShapesFunc composite,
 
             for (i = 0; i < nshapes; ++i) {
                 composite(op, src, dst, format,
-                          xSrc + src_xoff,
-                          ySrc + src_yoff,
-                          dst_xoff, dst_yoff, 1, shapes + i * shape_size);
+                          xSrc, ySrc, 0, 0, 
+                          1, shapes + i * shape_size);
             }
         }
         else {
@@ -143,8 +136,8 @@ fbShapes(CompositeShapesFunc composite,
             }
 
             composite(op, src, dst, format,
-                      xSrc + src_xoff,
-                      ySrc + src_yoff, dst_xoff, dst_yoff, nshapes, shapes);
+                      xSrc, ySrc, 0, 0,
+                      nshapes, shapes);
         }
 
         DamageRegionProcessPending(pDst->pDrawable);
