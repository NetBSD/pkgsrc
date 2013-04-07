$NetBSD: patch-libAfterImage_import.c,v 1.2 2013/04/07 10:36:54 cheusov Exp $
* fix for png-1.5
--- libAfterImage/import.c.orig	2010-09-23 20:57:57.000000000 +0000
+++ libAfterImage/import.c
@@ -1251,7 +1251,7 @@ png2ASImage_int( void *data, png_rw_ptr 
 			 * the normal method of doing things with libpng).  REQUIRED unless you
 			 * set up your own error handlers in the png_create_read_struct() earlier.
 			 */
-			if ( !setjmp (png_ptr->jmpbuf))
+			if ( !setjmp (png_jmpbuf(png_ptr)))
 			{
 				ASFlagType rgb_flags = ASStorage_RLEDiffCompress|ASStorage_32Bit ;
 
@@ -1447,8 +1447,8 @@ png2ASImage_int( void *data, png_rw_ptr 
 		}
 		/* clean up after the read, and free any memory allocated - REQUIRED */
 		png_destroy_read_struct (&png_ptr, &info_ptr, (png_infopp) NULL);
-		if (info_ptr)
-			free (info_ptr);
+//		if (info_ptr)
+//			free (info_ptr);
 	}
 
 #if defined(LOCAL_DEBUG) && !defined(NO_DEBUG_OUTPUT)
@@ -1468,7 +1468,7 @@ typedef struct ASImPNGReadBuffer
 
 static void asim_png_read_data(png_structp png_ptr, png_bytep data, png_size_t length)
 {
-   ASImPNGReadBuffer *buf = (ASImPNGReadBuffer *)png_ptr->io_ptr;
+   ASImPNGReadBuffer *buf = (ASImPNGReadBuffer *)png_get_io_ptr(png_ptr);
    memcpy(data, buf->buffer, length);
    buf->buffer += length;
 }
