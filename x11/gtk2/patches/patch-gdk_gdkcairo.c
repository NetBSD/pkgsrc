$NetBSD: patch-gdk_gdkcairo.c,v 1.1 2016/03/02 14:32:31 nros Exp $
Fix CVE-2013-7447.
Taken from gtk3.
https://web.nvd.nist.gov/view/vuln/detail?vulnId=CVE-2013-7447
--- gdk/gdkcairo.c.orig	2016-03-02 14:09:03.000000000 +0000
+++ gdk/gdkcairo.c
@@ -211,7 +211,7 @@ gdk_cairo_set_source_pixbuf (cairo_t    
     format = CAIRO_FORMAT_ARGB32;
 
   cairo_stride = cairo_format_stride_for_width (format, width);
-  cairo_pixels = g_malloc (height * cairo_stride);
+  cairo_pixels = g_malloc_n (height, cairo_stride);
   surface = cairo_image_surface_create_for_data ((unsigned char *)cairo_pixels,
                                                  format,
                                                  width, height, cairo_stride);
