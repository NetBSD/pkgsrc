$NetBSD: patch-libAfterStep_kde.c,v 1.1 2016/05/01 19:26:35 dholland Exp $

Use ctype.h correctly.

--- libAfterStep/kde.c~	2008-03-24 17:49:03.000000000 +0000
+++ libAfterStep/kde.c
@@ -110,14 +110,14 @@ xml_elem_t* load_KDE_config(const char* 
 			xml_elem_t* tag ; 
 			int i = 0; 
 
-			while( isspace(buffer[i]) ) ++i ;
+			while( isspace((unsigned char)buffer[i]) ) ++i ;
 			if( buffer[i] == '#' )
 			{
 				++i;
  				if( (tag = make_kde_config_comment_tag()) != NULL )
 				{	
 					int len = strlen( &buffer[i] ) ;
-					while( len > 0 && isspace( buffer[i+len-1] ) ) --len ;
+					while( len > 0 && isspace( (unsigned char)buffer[i+len-1] ) ) --len ;
 					if( len > 0 ) 
 					{
 						tag->child = create_CDATA_tag();	  
