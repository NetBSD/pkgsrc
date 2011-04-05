$NetBSD: patch-src_xtopng.c,v 1.1 2011/04/05 11:24:16 wiz Exp $

Fix build with png-1.5.

--- src/xtopng.c.orig	2004-02-14 10:55:36.000000000 +0000
+++ src/xtopng.c
@@ -110,7 +110,7 @@ XImageToPNGC (FILE *fp, XImage *image, J
 		png_destroy_write_struct (&png_ptr, (png_infopp)NULL);
 		return;
 	}
-	if (setjmp (png_ptr->jmpbuf)) {
+	if (setjmp (png_jmpbuf(png_ptr))) {
 		png_destroy_write_struct (&png_ptr, &info_ptr);
 		(*job->close) (fp);
 		return;
@@ -119,13 +119,14 @@ XImageToPNGC (FILE *fp, XImage *image, J
 	png_init_io (png_ptr, fp);
 	png_set_compression_level (png_ptr, job->compress);
 
-	info_ptr->width = image->width;
-	info_ptr->height= image->height;
-	info_ptr->bit_depth = 8;
-	info_ptr->color_type = PNG_COLOR_TYPE_RGB;
+	png_set_IHDR(png_ptr, info_ptr, image->width,
+		     image->height, 8, ((image->bits_per_pixel ==
+		     24) || (image->bits_per_pixel == 8)) ?
+		     PNG_COLOR_TYPE_RGB | PNG_COLOR_MASK_COLOR :
+		     PNG_COLOR_TYPE_RGB, PNG_INTERLACE_NONE,
+		     PNG_COMPRESSION_TYPE_BASE, PNG_FILTER_TYPE_BASE);
 	if ((image->bits_per_pixel == 16) ||
 		(image->bits_per_pixel == 8)) {
-		info_ptr->color_type |= PNG_COLOR_MASK_COLOR;
 		/* may be we need this? seems to be so
 		 */
 		png_set_sBIT (png_ptr, info_ptr, &sig_bit);
@@ -254,7 +255,7 @@ XImageToPNG8 (FILE *fp, XImage *image, J
 		png_destroy_read_struct (&png_ptr, (png_infopp)NULL, (png_infopp)NULL);
 		return;
 	}
-	if (setjmp (png_ptr->jmpbuf)) {
+	if (setjmp (png_jmpbuf(png_ptr))) {
 		png_destroy_write_struct (&png_ptr, &info_ptr);
 		(*job->close) (fp);
 		return;
@@ -263,13 +264,12 @@ XImageToPNG8 (FILE *fp, XImage *image, J
 	png_init_io (png_ptr, fp);
 	png_set_compression_level (png_ptr, job->compress);
 
-	info_ptr->width = image->width;
-	info_ptr->height= image->height;
-	info_ptr->bit_depth = 8;
-	if (job->win_attr.visual->class == StaticGray) {
-		info_ptr->color_type = PNG_COLOR_TYPE_GRAY;
-	} else {
-		info_ptr->color_type = PNG_COLOR_TYPE_PALETTE;
+	png_set_IHDR(png_ptr, info_ptr, image->width,
+		     image->height, 8, job->win_attr.visual->class
+		     == StaticGray ? PNG_COLOR_TYPE_GRAY :
+		     PNG_COLOR_TYPE_PALETTE, PNG_INTERLACE_NONE,
+		     PNG_COMPRESSION_TYPE_BASE, PNG_FILTER_TYPE_BASE);
+	if (job->win_attr.visual->class != StaticGray) {
 		png_set_PLTE (png_ptr, info_ptr, job->color_table, job->ncolors);
 	}
 
