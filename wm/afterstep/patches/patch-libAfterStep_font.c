$NetBSD: patch-libAfterStep_font.c,v 1.1 2016/05/01 19:26:35 dholland Exp $

Use ctype.h correctly.

--- libAfterStep/font.c~	2007-07-10 17:48:06.000000000 +0000
+++ libAfterStep/font.c
@@ -50,12 +50,12 @@ load_font (const char *name_in, MyFont *
 		register char *ptr = clean_name ;
 		while( ptr[i] ) ++i ;
 		while( --i >= 0 )
-			if( !isdigit(ptr[i]) )
+			if( !isdigit((unsigned char)ptr[i]) )
 				break;
-		if( (isspace( ptr[i] ) || ptr[i] == '-') && ptr[i+1] )
+		if( (isspace( (unsigned char)ptr[i] ) || ptr[i] == '-') && ptr[i+1] )
 		{
 			font_size = atoi( &(ptr[i+1]) );
-			while( i > 0 && isspace(ptr[i-1]) )	--i ;
+			while( i > 0 && isspace((unsigned char)ptr[i-1]) )	--i ;
 			clean_name = mystrndup( name, i );
 		}
 	}
