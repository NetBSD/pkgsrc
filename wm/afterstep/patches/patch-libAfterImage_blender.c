$NetBSD: patch-libAfterImage_blender.c,v 1.1 2025/10/23 01:28:08 gutteridge Exp $

Use ctype.h correctly.

--- libAfterImage/blender.c.orig	2013-05-01 13:34:11.000000000 +0000
+++ libAfterImage/blender.c
@@ -335,7 +335,7 @@ blend_scanlines_name2func( const char *n
 
 	if( name == NULL )
 		return NULL ;
-    while( isspace((int)*name) ) ++name;
+    while( isspace((unsigned char)*name) ) ++name;
 	do
 	{
 		if( name[0] == std_merge_scanlines_func_list[i].name[0] )
