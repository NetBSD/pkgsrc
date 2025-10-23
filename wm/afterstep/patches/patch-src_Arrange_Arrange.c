$NetBSD: patch-src_Arrange_Arrange.c,v 1.1 2025/10/23 01:28:08 gutteridge Exp $

Use ctype.h correctly.

--- src/Arrange/Arrange.c.orig	2013-05-01 13:34:11.000000000 +0000
+++ src/Arrange/Arrange.c
@@ -263,7 +263,7 @@ main( int argc, char **argv )
 		  the first window (default 0, 0). The second pair
 		  specify a maximal width and height for layered windows.
 		*/
-		if( isdigit( argv[i][0] ) )
+		if( isdigit( (unsigned char)argv[i][0] ) )
 		{
 			if( nargc == 0 ) 
 			{	
