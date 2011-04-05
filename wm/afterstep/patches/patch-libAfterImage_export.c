$NetBSD: patch-libAfterImage_export.c,v 1.1 2011/04/05 12:02:00 wiz Exp $

Fix build with png-1.5.

--- libAfterImage/export.c.orig	2005-03-09 23:59:06.000000000 +0000
+++ libAfterImage/export.c
@@ -371,7 +371,7 @@ ASImage2png_int ( ASImage *im, void *dat
 	png_ptr = png_create_write_struct( PNG_LIBPNG_VER_STRING, NULL, NULL, NULL );
     if ( png_ptr != NULL )
     	if( (info_ptr = png_create_info_struct(png_ptr)) != NULL )
-			if( setjmp(png_ptr->jmpbuf) )
+			if( setjmp(png_jmpbuf(png_ptr)) )
 			{
 				png_destroy_info_struct(png_ptr, (png_infopp) &info_ptr);
 				info_ptr = NULL ;
