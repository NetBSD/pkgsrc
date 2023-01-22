$NetBSD: patch-xdnotify_xtmNotify.c,v 1.1 2023/01/22 20:08:17 vins Exp $

Fix warnings about int signedness mismatch.
Fix void main().

--- xdnotify/xtmNotify.c.orig	1997-05-04 22:02:15.000000000 +0000
+++ xdnotify/xtmNotify.c
@@ -244,8 +244,8 @@ static void
 --  Functions
 ----------------------------------------------------------------------------*/
 
-void 
-  main( unsigned int argc, char *argv[] )
+int 
+  main( int argc, char *argv[] )
 {
 
   /* Variables. */
