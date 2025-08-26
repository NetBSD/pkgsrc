$NetBSD: patch-gdk_quartz_gdkimage-quartz.c,v 1.1 2025/08/26 04:36:17 pho Exp $

Fix "Source with depth 1 unsupported" warnings on Darwin/Quartz.
- Upstream ticket: https://gitlab.gnome.org/GNOME/gtk/-/issues/580
- Patch from: https://trac.macports.org/ticket/69291

--- gdk/quartz/gdkimage-quartz.c.orig	2020-12-18 05:29:39.000000000 +0000
+++ gdk/quartz/gdkimage-quartz.c
@@ -37,15 +37,16 @@ _gdk_quartz_image_copy_to_image (GdkDraw
 				 gint         height)
 {
   GdkScreen *screen;
+  int depth;
   
   g_return_val_if_fail (GDK_IS_DRAWABLE_IMPL_QUARTZ (drawable), NULL);
   g_return_val_if_fail (image != NULL || (dest_x == 0 && dest_y == 0), NULL);
 
   screen = gdk_drawable_get_screen (drawable);
+  depth = gdk_drawable_get_depth (drawable);
   if (!image)
     image = _gdk_image_new_for_depth (screen, GDK_IMAGE_FASTEST, NULL, 
-				      width, height,
-				      gdk_drawable_get_depth (drawable));
+				      width, height, depth);
   
   if (GDK_IS_PIXMAP_IMPL_QUARTZ (drawable))
     {
@@ -63,7 +64,7 @@ _gdk_quartz_image_copy_to_image (GdkDraw
           return image;
         }
 
-      switch (gdk_drawable_get_depth (drawable))
+      switch (depth)
         {
         case 24:
           bytes_per_row = pix_impl->width * 4;
@@ -123,7 +124,7 @@ _gdk_quartz_image_copy_to_image (GdkDraw
           break;
 
         default:
-          g_warning ("Unsupported bit depth %d\n", gdk_drawable_get_depth (drawable));
+          g_warning ("Unsupported bit depth %d\n", depth);
           return image;
         }
     }
@@ -322,7 +323,7 @@ _gdk_image_new_for_depth (GdkScreen    *
   if (visual)
     depth = visual->depth;
 
-  g_assert (depth == 24 || depth == 32);
+  g_assert (depth == 1 || depth == 24 || depth == 32);
 
   image = g_object_new (gdk_image_get_type (), NULL);
   image->type = type;
@@ -333,11 +334,16 @@ _gdk_image_new_for_depth (GdkScreen    *
 
   image->byte_order = (G_BYTE_ORDER == G_LITTLE_ENDIAN) ? GDK_LSB_FIRST : GDK_MSB_FIRST;
 
-  /* We only support images with bpp 4 */
-  image->bpp = 4;
-  image->bpl = image->width * image->bpp;
-  image->bits_per_pixel = image->bpp * 8;
-  
+  if (depth == 1) {
+    image->bpp = 1;
+    image->bpl = (image->width >> 3) + 1;
+    image->bits_per_pixel = 1;
+  } else {
+    image->bpp = 4;
+    image->bpl = image->width * image->bpp;
+    image->bits_per_pixel = image->bpp * 8;
+  }
+ 
   image->mem = g_malloc (image->bpl * image->height);
   memset (image->mem, 0x00, image->bpl * image->height);
 
@@ -355,7 +361,14 @@ gdk_image_get_pixel (GdkImage *image,
   g_return_val_if_fail (x >= 0 && x < image->width, 0);
   g_return_val_if_fail (y >= 0 && y < image->height, 0);
 
-  ptr = image->mem + y * image->bpl + x * image->bpp;
+  ptr = image->mem + y * image->bpl;
+  if (image->depth == 1) {
+    guchar data = (image->byte_order == GDK_MSB_FIRST ? (0x80 >> (x & 7)) : (1 << (x & 7)));
+    return (ptr[x >> 3] & data) ? 0x1 : 0x0;
+  } else {
+    ptr += x * image->bpp;
+    return *(guint32 *)ptr;
+  }
 
   return *(guint32 *)ptr;
 }
@@ -366,9 +379,18 @@ gdk_image_put_pixel (GdkImage *image,
 		     gint y,
 		     guint32 pixel)
 {
-  guchar *ptr;
-
-  ptr = image->mem + y * image->bpl + x * image->bpp;
+  guchar *ptr = image->mem + y * image->bpl;
+  if (image->depth == 1) {
+    guchar data = (image->byte_order == GDK_MSB_FIRST ? (0x80 >> (x & 7)) : (1 << (x & 7)));
+    if (pixel) {
+        ptr[x >> 3] |= data;
+    } else {
+        ptr[x >> 3] &= ~data;
+    }
+  } else {
+    ptr += x * image->bpp;
+    *(guint32 *)ptr = pixel;
+  }
 
   *(guint32 *)ptr = pixel;
 }
@@ -377,7 +399,9 @@ gint
 _gdk_windowing_get_bits_for_depth (GdkDisplay *display,
 				   gint        depth)
 {
-  if (depth == 24 || depth == 32)
+  if (depth == 1)
+    return 1;
+  else if (depth == 24 || depth == 32)
     return 32;
   else
     g_assert_not_reached ();
