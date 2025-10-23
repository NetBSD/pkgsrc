$NetBSD: patch-src_WinCommand_WinCommand.c,v 1.1 2025/10/23 01:28:09 gutteridge Exp $

Use ctype.h correctly.

--- src/WinCommand/WinCommand.c.orig	2013-05-01 13:34:11.000000000 +0000
+++ src/WinCommand/WinCommand.c
@@ -231,32 +231,32 @@ set_WinCommandParam( ASWinCommandState *
 		++param ;
 	if( mystrcasecmp ( param, "x") == 0)
 	{
-		if( val == NULL || !isdigit(val[0]) ) 
+		if( val == NULL || !isdigit((unsigned char)val[0]) ) 
 			return ASWC_BadVal;
 		state->x_dest = atopixel( val, Scr.MyDisplayWidth);
 		++val_used;
 	}else if( mystrcasecmp ( param, "y") == 0)
 	{
-		if( val == NULL || !isdigit(val[0]) ) 
+		if( val == NULL || !isdigit((unsigned char)val[0]) ) 
 			return ASWC_BadVal;
 		state->y_dest = atopixel( val, Scr.MyDisplayHeight);
 		++val_used;
 	}else			/* Resize */
 		if( mystrcasecmp ( param, "width") == 0 )
 	{
-		if( val == NULL || !isdigit(val[0]) ) 
+		if( val == NULL || !isdigit((unsigned char)val[0]) ) 
 			return ASWC_BadVal;
 		state->new_width = atopixel ( val, Scr.MyDisplayWidth);
 		++val_used;
 	}else if( mystrcasecmp ( param, "height") == 0 )
 	{
-		if( val == NULL || !isdigit(val[0]) ) 
+		if( val == NULL || !isdigit((unsigned char)val[0]) ) 
 			return ASWC_BadVal;
 		state->new_height = atopixel ( val, Scr.MyDisplayHeight);
 		++val_used;
 	}else if( mystrcasecmp ( param, "new_desk") == 0 )
 	{
-		if( val == NULL || !isdigit(val[0]) ) 
+		if( val == NULL || !isdigit((unsigned char)val[0]) ) 
 			return ASWC_BadVal;
 		state->desk = atoi( val );
 		++val_used;
@@ -396,7 +396,7 @@ main( int argc, char **argv )
 				{
 					char *param = 	NULL ; 
 					ptr = parse_token (ptr, &param);
-					while( isspace(*ptr) ) ++ptr ;
+					while( isspace((unsigned char)*ptr) ) ++ptr ;
 					switch( set_WinCommandParam( &WinCommandState, param, ptr) )
 					{
 						case ASWC_BadParam :
