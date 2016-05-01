$NetBSD: patch-libAfterImage_import.c,v 1.3 2016/05/01 19:26:35 dholland Exp $

- use ctype.h correctly
- fix for png-1.5

--- libAfterImage/import.c.orig	2010-09-23 20:57:57.000000000 +0000
+++ libAfterImage/import.c
@@ -221,7 +221,7 @@ char *locate_image_file_in_path( const c
 		if( realfilename == NULL )
 		{ /* let's try and see if we have subimage number appended */
 			for( i = filename_len-1 ; i > 0; i-- )
-				if( !isdigit( (int)tmp[i] ) )
+				if( !isdigit( (unsigned char)tmp[i] ) )
 					break;
 			if( i < filename_len-1 && i > 0 )
 				if( tmp[i] == '.' )                 /* we have possible subimage number */
@@ -878,7 +878,7 @@ load_asimage_list_entry_data( ASImageLis
 		int i = entry->buffer->size ; 
 		register char *ptr = entry->buffer->data ;
 		while ( --i >= 0 )	
-			if( !isprint(ptr[i]) && ptr[i] != '\n'&& ptr[i] != '\r'&& ptr[i] != '\t' )	
+			if( !isprint((unsigned char)ptr[i]) && ptr[i] != '\n'&& ptr[i] != '\r'&& ptr[i] != '\t' )	
 				break;
 		binary = (i >= 0);				
 	}else
@@ -980,7 +980,7 @@ check_image_type( const char *realfilena
 				type = ASIT_Gif;
 			else if (head[0] == head[1] && (head[0] == 'I' || head[0] == 'M'))
 				type = ASIT_Tiff;
-			else if (head[0] == 'P' && isdigit(head[1]))
+			else if (head[0] == 'P' && isdigit((unsigned char)head[1]))
 				type = (head[1]!='5' && head[1]!='6')?ASIT_Pnm:ASIT_Ppm;
 			else if (head[0] == 0xa && head[1] <= 5 && head[2] == 1)
 				type = ASIT_Pcx;
@@ -1014,13 +1014,13 @@ check_image_type( const char *realfilena
 				int i ;
 
 				type = ASIT_XMLScript ;
-				for( i = 0 ; i < bytes_in ; ++i ) if( !isspace(head[i]) ) break;
+				for( i = 0 ; i < bytes_in ; ++i ) if( !isspace((unsigned char)head[i]) ) break;
 				while( bytes_in > 0 && type == ASIT_XMLScript )
 				{
 					if( i >= bytes_in )
 					{	
 						bytes_in = fread( &(head[0]), sizeof(CARD8), FILE_HEADER_SIZE, fp );
-						for( i = 0 ; i < bytes_in ; ++i ) if( !isspace(head[i]) ) break;
+						for( i = 0 ; i < bytes_in ; ++i ) if( !isspace((unsigned char)head[i]) ) break;
 					}
 					else if( head[i] != '<' )
 						type = ASIT_Unknown ;
@@ -1030,7 +1030,7 @@ check_image_type( const char *realfilena
 					}else if( mystrncasecmp( &(head[i]), "<!DOCTYPE ", 10 ) == 0 ) 
 					{	
 						type = ASIT_XML ;
-						for( i += 9 ; i < bytes_in ; ++i ) if( !isspace(head[i]) ) break;
+						for( i += 9 ; i < bytes_in ; ++i ) if( !isspace((unsigned char)head[i]) ) break;
 						if( i < bytes_in ) 
 						{
 					 		if( mystrncasecmp( &(head[i]), "afterstep-image-xml", 19 ) == 0 ) 			
@@ -1044,9 +1044,9 @@ check_image_type( const char *realfilena
 						while( bytes_in > 0 && type == ASIT_XMLScript )
 						{
 							while( ++i < bytes_in )
-								if( !isspace(head[i]) )
+								if( !isspace((unsigned char)head[i]) )
 								{
-									if( !isprint(head[i]) )
+									if( !isprint((unsigned char)head[i]) )
 									{
 										type = ASIT_Unknown ;
 										break ;
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
@@ -1828,8 +1828,8 @@ ppm2ASImage( const char * path, ASImageI
 						break;
 					}
 					width = atoi( &(buffer[i]) );
-					while ( buffer[i] != '\0' && !isspace((int)buffer[i]) ) ++i;
-					while ( isspace((int)buffer[i]) ) ++i;
+					while ( buffer[i] != '\0' && !isspace((unsigned char)buffer[i]) ) ++i;
+					while ( isspace((unsigned char)buffer[i]) ) ++i;
 					if( buffer[i] != '\0')
 						height = atoi(&(buffer[i]));
 				}
