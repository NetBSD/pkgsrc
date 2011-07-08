$NetBSD: patch-fvwm-insitu_libs_PictureImageLoader.c,v 1.1 2011/07/08 20:57:02 wiz Exp $

Fix build with png-1.5.

--- fvwm-insitu/libs/PictureImageLoader.c.orig	2008-12-09 12:52:20.000000000 +0000
+++ fvwm-insitu/libs/PictureImageLoader.c
@@ -165,16 +165,16 @@ Bool PImageLoadPng(FIMAGE_CMD_ARGS)
 	{
 		Fpng_set_expand(Fpng_ptr);
 	}
-	if (Finfo_ptr->color_type == FPNG_COLOR_TYPE_RGB_ALPHA)
+	if (png_get_color_type(Fpng_ptr, Finfo_ptr) == FPNG_COLOR_TYPE_RGB_ALPHA)
 	{
 		hasa = 1;
 	}
-	if (Finfo_ptr->color_type == FPNG_COLOR_TYPE_GRAY_ALPHA)
+	if (png_get_color_type(Fpng_ptr, Finfo_ptr) == FPNG_COLOR_TYPE_GRAY_ALPHA)
 	{
 		hasa = 1;
 		hasg = 1;
 	}
-	if (Finfo_ptr->color_type == FPNG_COLOR_TYPE_GRAY)
+	if (png_get_color_type(Fpng_ptr, Finfo_ptr) == FPNG_COLOR_TYPE_GRAY)
 	{
 		hasg = 1;
 	}
