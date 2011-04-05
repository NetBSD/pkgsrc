$NetBSD: patch-libAfterImage_import.c,v 1.1 2011/04/05 12:02:00 wiz Exp $

Fix build with png-1.5.

--- libAfterImage/import.c.orig	2005-06-21 22:58:24.000000000 +0000
+++ libAfterImage/import.c
@@ -876,7 +876,7 @@ png2ASImage( const char * path, ASImageI
 			 * the normal method of doing things with libpng).  REQUIRED unless you
 			 * set up your own error handlers in the png_create_read_struct() earlier.
 			 */
-			if ( !setjmp (png_ptr->jmpbuf))
+			if ( !setjmp (png_jmpbuf(png_ptr)))
 			{
 				ASFlagType rgb_flags = ASStorage_RLEDiffCompress|ASStorage_32Bit ;
 				
