$NetBSD: patch-xdlight_xtmDiaryLgt.c,v 1.1 2023/01/22 20:08:17 vins Exp $

Fix warnings about int signedness mismatch.
Fix void main().

--- xdlight/xtmDiaryLgt.c.orig	1997-05-04 23:13:08.000000000 +0000
+++ xdlight/xtmDiaryLgt.c
@@ -220,8 +220,8 @@ static void
 --  Functions
 ----------------------------------------------------------------------------*/
 
-void 
-  main( unsigned int argc, char **argv )
+int 
+  main( int argc, char **argv )
 {
 
   /* Variables. */
