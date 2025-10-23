$NetBSD: patch-src_ASConfig_ASConfig.c,v 1.1 2025/10/23 01:28:08 gutteridge Exp $

Use ctype.h correctly.

--- src/ASConfig/ASConfig.c.orig	2013-05-01 13:34:11.000000000 +0000
+++ src/ASConfig/ASConfig.c
@@ -665,7 +665,7 @@ asmenu_dir2property( const char *dirname
 		ptr = dirname ;
 	else
 		++ptr ;
-	while( isdigit(*ptr) ) ++ptr;
+	while( isdigit((unsigned char)*ptr) ) ++ptr;
 	if( *ptr == '_' )
 		++ptr ;
 	
@@ -715,7 +715,7 @@ asmenu_dir2property( const char *dirname
 			
 			if( clean_name == list[i]->d_name )
 			{	
-				if( isalpha(clean_name[0]) && clean_name[1] == '_' )
+				if( isalpha((unsigned char)clean_name[0]) && clean_name[1] == '_' )
 				{	
 					order = (int)(clean_name[0]) - (int)'0' ;
 					clean_name += 2 ;
