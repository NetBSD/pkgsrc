$NetBSD: patch-libAfterImage_xpm.c,v 1.1 2025/10/23 01:28:08 gutteridge Exp $

Use ctype.h correctly.

--- libAfterImage/xpm.c.orig	2013-05-01 13:34:11.000000000 +0000
+++ libAfterImage/xpm.c
@@ -468,8 +468,8 @@ parse_xpm_cmap_entry( ASXpmFile *xpm_fil
 	key = -1;
 	do
 	{
-        while( !isspace((int)*ptr) && *ptr != '\0' ) ++ptr;
-        while( isspace((int)*ptr) ) ++ptr;
+        while( !isspace((unsigned char)*ptr) && *ptr != '\0' ) ++ptr;
+        while( isspace((unsigned char)*ptr) ) ++ptr;
 		if( *ptr )
 		{
 			if( key >= 0 )
@@ -702,22 +702,22 @@ parse_xpm_header( ASXpmFile *xpm_file )
 		return False;
 
 	ptr = xpm_file->str_buf ;
-	while( isspace((int)*ptr) ) ++ptr;
+	while( isspace((unsigned char)*ptr) ) ++ptr;
 	if( *ptr == '\0' )
 		return False;
 	xpm_file->width = atoi( ptr );
-	while( !isspace((int)*ptr) && *ptr != '\0' ) ++ptr;
-	while( isspace((int)*ptr) ) ++ptr;
+	while( !isspace((unsigned char)*ptr) && *ptr != '\0' ) ++ptr;
+	while( isspace((unsigned char)*ptr) ) ++ptr;
 	if( *ptr == '\0' )
 		return False;
 	xpm_file->height = atoi( ptr );
-	while( !isspace((int)*ptr) && *ptr != '\0' ) ++ptr;
-	while( isspace((int)*ptr) ) ++ptr;
+	while( !isspace((unsigned char)*ptr) && *ptr != '\0' ) ++ptr;
+	while( isspace((unsigned char)*ptr) ) ++ptr;
 	if( *ptr == '\0' )
 		return False;
 	xpm_file->cmap_size = atoi( ptr );
-	while( !isspace((int)*ptr) && *ptr != '\0' ) ++ptr;
-	while( isspace((int)*ptr) ) ++ptr;
+	while( !isspace((unsigned char)*ptr) && *ptr != '\0' ) ++ptr;
+	while( isspace((unsigned char)*ptr) ) ++ptr;
 	if( *ptr == '\0' )
 		return False;
 	xpm_file->bpp = atoi( ptr );
