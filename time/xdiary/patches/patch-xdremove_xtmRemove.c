$NetBSD: patch-xdremove_xtmRemove.c,v 1.1 2023/01/22 20:08:17 vins Exp $

Use fgets() instead of gets()

--- xdremove/xtmRemove.c.orig	1997-05-04 22:02:15.000000000 +0000
+++ xdremove/xtmRemove.c
@@ -290,8 +290,8 @@ main( int argc, char *argv[] )
             appl_data.days, buffer, appl_data.database_dir );
     printf( "Is this OK? (Y/N) [N]: " );
 
-    gets( buffer );
-    if( toupper( buffer[ 0 ] ) != 'Y' )
+    fgets(buffer, sizeof(buffer), stdin);
+	if( toupper( buffer[ 0 ] ) != 'Y' )
       exit( 0 );
   }
 
