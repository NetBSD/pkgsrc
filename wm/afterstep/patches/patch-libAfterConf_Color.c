$NetBSD: patch-libAfterConf_Color.c,v 1.1 2016/05/01 19:26:35 dholland Exp $

Use ctype.h correctly.
Fix some printf formats.

--- libAfterConf/Color.c~	2008-03-21 22:48:51.000000000 +0000
+++ libAfterConf/Color.c
@@ -326,7 +326,7 @@ translate_gtkrc_template_file( 	const ch
 		while( fgets( &buffer[0], MAXLINELENGTH, src_fp ) )
 		{
 			int i = 0; 
-			while( isspace(buffer[i]) )++i ; 
+			while( isspace((unsigned char)buffer[i]) )++i ; 
 			if( buffer[i] != '\n' && buffer[i] != '#' && buffer[i] != '\0' && buffer[i] != '\r' )
 			{	
 				++good_strings;
@@ -342,7 +342,7 @@ translate_gtkrc_template_file( 	const ch
 					if(buffer[i] == '\"' )
 					{
 					 	char *token = &buffer[i+1] ;
-						if( isalpha(token[0]) ) 
+						if( isalpha((unsigned char)token[0]) ) 
 						{	
 							int len = 0 ; 
 							while( token[len] != '\0' && token[len] != '\"' ) ++len ; 
@@ -352,7 +352,7 @@ translate_gtkrc_template_file( 	const ch
 								if( parse_argb_color( token, &argb ) != token ) 
 								{	
 						 			fwrite( &(buffer[0]), 1, i+1, dst_fp );
-									fprintf( dst_fp, "#%2.2lX%2.2lX%2.2lX", ARGB32_RED8(argb), ARGB32_GREEN8(argb), ARGB32_BLUE8(argb) );
+									fprintf( dst_fp, "#%2.2lX%2.2lX%2.2lX", (unsigned long)ARGB32_RED8(argb), (unsigned long)ARGB32_GREEN8(argb), (unsigned long)ARGB32_BLUE8(argb) );
 									fwrite( &(token[len]), 1, strlen(&(token[len])), dst_fp );
 									continue;
 								}
@@ -398,7 +398,7 @@ translate_kcsrc_template_file( 	const ch
 					if( parse_argb_color( parm, &argb ) != parm ) 
 					{	
 						char *tmp = safemalloc( 32 );
-						sprintf( tmp, "%ld,%ld,%ld", ARGB32_RED8(argb), ARGB32_GREEN8(argb), ARGB32_BLUE8(argb) );						 				   
+						sprintf( tmp, "%ld,%ld,%ld", (unsigned long)ARGB32_RED8(argb), (unsigned long)ARGB32_GREEN8(argb), (unsigned long)ARGB32_BLUE8(argb) );						 				   
 						free( item->child->parm );
 						item->child->parm = tmp;
 					}							
