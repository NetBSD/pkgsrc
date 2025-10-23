$NetBSD: patch-src_ascp_asimbrowser.c,v 1.1 2025/10/23 01:28:09 gutteridge Exp $

Use ctype.h correctly.

--- src/ascp/asimbrowser.c.orig	2013-05-01 13:34:11.000000000 +0000
+++ src/ascp/asimbrowser.c
@@ -521,7 +521,7 @@ void generate_dir_html( char *dir, char 
 										++body_count;
 									else if(  c == '>' && body_count == 4 )
 										++body_count;
-									else if( !isspace( c ) || (body_count > 0 && body_count < 4) )
+									else if( !isspace( (unsigned char)c ) || (body_count > 0 && body_count < 4) )
 									{
 										body_count = -1 ;
 									}
@@ -546,7 +546,7 @@ void generate_dir_html( char *dir, char 
 						{
 							if( valid_html )
 								fputc( c, frame_of );
-							else if( !isascii( c ) )
+							else if( !isascii( (unsigned char)c ) )
 								fprintf( frame_of, "#%2.2X;", c );
 							else if( c == '<' )
 								fprintf( frame_of, "&lt;" );
