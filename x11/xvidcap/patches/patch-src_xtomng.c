$NetBSD: patch-src_xtomng.c,v 1.1 2011/04/05 11:24:16 wiz Exp $

Fix build with png-1.5.

--- src/xtomng.c.orig	2004-02-14 10:55:36.000000000 +0000
+++ src/xtomng.c
@@ -110,19 +110,18 @@ XImageToMNGC (FILE *fp, XImage *image, J
 			png_destroy_write_struct (&png_ptr, (png_infopp)NULL);
 			return;
 		}
-		if (setjmp (png_ptr->jmpbuf)) {
+		if (setjmp (png_jmpbuf(png_ptr))) {
 			png_destroy_write_struct (&png_ptr, &info_ptr);
 			(*job->close) (fp);
 			exit(99);
 		}
 
-		info_ptr->width = image->width;
-		info_ptr->height= image->height;
-		info_ptr->bit_depth = 8;
-		info_ptr->color_type = PNG_COLOR_TYPE_RGB;
-		if (image->bits_per_pixel != 24) {
-			info_ptr->color_type |= PNG_COLOR_MASK_COLOR;
-		}
+		png_set_IHDR(png_ptr, info_ptr, image->width,
+			     image->height, 8, image->bits_per_pixel
+			     != 24 ? PNG_COLOR_TYPE_RGB |
+			     PNG_COLOR_MASK_COLOR : PNG_COLOR_TYPE_RGB,
+			     PNG_INTERLACE_NONE, PNG_COMPRESSION_TYPE_BASE,
+			     PNG_FILTER_TYPE_BASE);
 		mng_write_sig (png_ptr);
 		mng_write_MHDR (png_ptr, image->width, image->height, 1000 /* msec */);
 		mng_write_nEED (png_ptr, "draft 41");
@@ -354,19 +353,17 @@ XImageToMNG8 (FILE *fp, XImage *image, J
 			png_destroy_write_struct (&png_ptr, (png_infopp)NULL);
 			return;
 		}
-		if (setjmp (png_ptr->jmpbuf)) {
+		if (setjmp (png_jmpbuf(png_ptr))) {
 			png_destroy_write_struct (&png_ptr, &info_ptr);
 			(*job->close)(fp);
 			exit (99);
 		}
-		info_ptr->width = image->width;
-		info_ptr->height= image->height;
-		info_ptr->bit_depth = 8;
-		if (job->win_attr.visual->class == StaticGray) {
-			info_ptr->color_type = PNG_COLOR_TYPE_GRAY;
-		} else {
-			info_ptr->color_type = PNG_COLOR_TYPE_PALETTE;
-		}
+		png_set_IHDR(png_ptr, info_ptr, image->width,
+			     image->height, 8, job->win_attr.visual->class
+			     == StaticGray ? PNG_COLOR_TYPE_GRAY
+			     : PNG_COLOR_TYPE_PALETTE, PNG_INTERLACE_NONE,
+			     PNG_COMPRESSION_TYPE_BASE,
+			     PNG_FILTER_TYPE_BASE);
 		mng_write_sig (png_ptr),
 		mng_write_MHDR (png_ptr, image->width, image->height, 1000 /* msec */);
 		mng_write_nEED (png_ptr, "draft 41");
