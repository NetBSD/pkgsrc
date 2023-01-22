$NetBSD: patch-xdremind_xtmRemMain.c,v 1.1 2023/01/22 20:08:17 vins Exp $

Fix warnings about int signedness mismatch.
Fix void main().

--- xdremind/xtmRemMain.c.orig	1997-05-04 22:02:15.000000000 +0000
+++ xdremind/xtmRemMain.c
@@ -177,8 +177,8 @@ static void
 --  Functions
 ----------------------------------------------------------------------------*/
 
-void 
-  main( unsigned int argc, char *argv[] )
+int 
+  main( int argc, char *argv[] )
 {
 
   /* Variables. */
