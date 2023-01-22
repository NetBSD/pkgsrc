$NetBSD: patch-xdiary_xtmDiary.c,v 1.1 2023/01/22 20:08:17 vins Exp $

Fix void main().

--- xdiary/xtmDiary.c.orig	1997-05-05 23:13:48.000000000 +0000
+++ xdiary/xtmDiary.c
@@ -213,7 +213,7 @@ static void
 --  Functions
 ----------------------------------------------------------------------------*/
 
-void 
+int 
   main( int argc, char **argv )
 {
 
