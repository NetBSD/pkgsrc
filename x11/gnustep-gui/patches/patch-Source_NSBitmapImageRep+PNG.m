$NetBSD: patch-Source_NSBitmapImageRep+PNG.m,v 1.1 2013/02/26 23:35:25 joerg Exp $

--- Source/NSBitmapImageRep+PNG.m.orig	2013-02-26 13:18:16.000000000 +0000
+++ Source/NSBitmapImageRep+PNG.m
@@ -359,7 +359,7 @@ static void writer_func(png_structp png_
 
   // init structures
   PNGRep = [NSMutableData dataWithLength: 0];
-  png_info_init_3(&png_info, png_sizeof(png_info));
+  png_info_init_3(&png_info, sizeof(png_info));
   png_set_write_fn(png_struct, PNGRep, writer_func, NULL);
   png_set_IHDR(png_struct, png_info, width, height, depth,
    type, interlace, PNG_COMPRESSION_TYPE_BASE,
