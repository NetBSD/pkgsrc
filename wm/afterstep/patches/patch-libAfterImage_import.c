$NetBSD: patch-libAfterImage_import.c,v 1.4 2021/07/11 12:13:17 bsiegert Exp $

- use ctype.h correctly
- fix for png-1.5

--- libAfterImage/import.c.orig	2013-05-01 13:34:11.000000000 +0000
+++ libAfterImage/import.c
@@ -216,7 +216,7 @@ char *locate_image_file_in_path( const c
 		if( realfilename == NULL )
 		{ /* let's try and see if we have subimage number appended */
 			for( i = filename_len-1 ; i > 0; i-- )
-				if( !isdigit( (int)tmp[i] ) )
+				if( !isdigit( (unsigned char)tmp[i] ) )
 					break;
 			if( i < filename_len-1 && i > 0 )
 				if( tmp[i] == '.' )                 /* we have possible subimage number */
@@ -1023,7 +1023,7 @@ load_asimage_list_entry_data( ASImageLis
 		int i = entry->buffer->size ; 
 		register char *ptr = entry->buffer->data ;
 		while ( --i >= 0 )	
-			if( !isprint(ptr[i]) && ptr[i] != '\n'&& ptr[i] != '\r'&& ptr[i] != '\t' )	
+			if( !isprint((unsigned char)ptr[i]) && ptr[i] != '\n'&& ptr[i] != '\r'&& ptr[i] != '\t' )	
 				break;
 		binary = (i >= 0);				
 	}else
@@ -1125,7 +1125,7 @@ check_image_type( const char *realfilena
 				type = ASIT_Gif;
 			else if (head[0] == head[1] && (head[0] == 'I' || head[0] == 'M'))
 				type = ASIT_Tiff;
-			else if (head[0] == 'P' && isdigit(head[1]))
+			else if (head[0] == 'P' && isdigit((unsigned char)head[1]))
 				type = (head[1]!='5' && head[1]!='6')?ASIT_Pnm:ASIT_Ppm;
 			else if (head[0] == 0xa && head[1] <= 5 && head[2] == 1)
 				type = ASIT_Pcx;
@@ -1159,13 +1159,13 @@ check_image_type( const char *realfilena
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
@@ -1175,7 +1175,7 @@ check_image_type( const char *realfilena
 					}else if( mystrncasecmp( &(head[i]), "<!DOCTYPE ", 10 ) == 0 ) 
 					{	
 						type = ASIT_XML ;
-						for( i += 9 ; i < bytes_in ; ++i ) if( !isspace(head[i]) ) break;
+						for( i += 9 ; i < bytes_in ; ++i ) if( !isspace((unsigned char)head[i]) ) break;
 						if( i < bytes_in ) 
 						{
 					 		if( mystrncasecmp( &(head[i]), "afterstep-image-xml", 19 ) == 0 ) 			
@@ -1189,9 +1189,9 @@ check_image_type( const char *realfilena
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
@@ -1592,8 +1592,8 @@ png2ASImage_int( void *data, png_rw_ptr 
 		}
 		/* clean up after the read, and free any memory allocated - REQUIRED */
 		png_destroy_read_struct (&png_ptr, &info_ptr, (png_infopp) NULL);
-		if (info_ptr)
-			free (info_ptr);
+//		if (info_ptr)
+//			free (info_ptr);
 	}
 
 #if defined(LOCAL_DEBUG) && !defined(NO_DEBUG_OUTPUT)
@@ -1973,8 +1973,8 @@ ppm2ASImage( const char * path, ASImageI
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
