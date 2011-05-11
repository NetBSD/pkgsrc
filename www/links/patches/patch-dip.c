$NetBSD: patch-dip.c,v 1.1 2011/05/11 16:46:16 wiz Exp $

From John Bowler <jbowler@acm.org>:
It's two bugs: one, the obvious one, in the two calls to
png_set_rgb_to_gray() in dip.c; that should be *DIVIDED* by 256,
not multiplied!
                                                                                                                                                                                                                    
The other is that there is *NO* error handling, no call to setjmp();
so when png_error is called the call stack ends up destroyed and,
apparently, the program dies in create_read_struct_2, right after
the comment that explains why libpng is about to call abort() ;-)
                                                                                                                                                                                                                    
The attached patch fixes both problems, but links will still error
out on a png_error (just with an OOM message, not an abort()).

--- dip.c.orig	2011-04-19 15:17:48.000000000 +0000
+++ dip.c
@@ -1422,6 +1422,8 @@ unsigned char *png_data, int png_length,
 	
 	png_ptr=png_create_read_struct(PNG_LIBPNG_VER_STRING,
 			NULL, my_png_error, my_png_warning);
+	if (setjmp(png_jmpbuf(png_ptr)))
+	    overalloc(); /* some error detected by libpng */
 	info_ptr=png_create_info_struct(png_ptr);
 	png_set_read_fn(png_ptr,&work,(png_rw_ptr)&read_stored_data);
 	png_read_info(png_ptr, info_ptr);
@@ -1448,7 +1450,7 @@ unsigned char *png_data, int png_length,
 		if (color_type==PNG_COLOR_TYPE_PALETTE){
 			png_set_expand(png_ptr);
 #ifdef HAVE_PNG_SET_RGB_TO_GRAY
-			png_set_rgb_to_gray(png_ptr,1,54.0*256,183.0*256);
+			png_set_rgb_to_gray(png_ptr,1,54.0/256,183.0/256);
 #else
 			goto end;
 #endif
@@ -1459,7 +1461,7 @@ unsigned char *png_data, int png_length,
 		if (color_type==PNG_COLOR_TYPE_RGB ||
 			color_type==PNG_COLOR_TYPE_RGB_ALPHA){
 #ifdef HAVE_PNG_SET_RGB_TO_GRAY
-			png_set_rgb_to_gray(png_ptr, 1, 54.0*256, 183.0*256);
+			png_set_rgb_to_gray(png_ptr, 1, 54.0/256, 183.0/256);
 #else
 			goto end;
 #endif
