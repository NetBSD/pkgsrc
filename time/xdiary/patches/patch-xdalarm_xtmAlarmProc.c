$NetBSD: patch-xdalarm_xtmAlarmProc.c,v 1.1 2023/01/22 20:08:17 vins Exp $

Fix warnings about int signedness mismatch.
Fix void main().

--- xdalarm/xtmAlarmProc.c.orig	1997-05-04 22:02:19.000000000 +0000
+++ xdalarm/xtmAlarmProc.c
@@ -452,8 +452,8 @@ static void
 --  Functions
 ----------------------------------------------------------------------------*/
 
-void 
-  main( unsigned int argc, char *argv[] )
+int 
+  main( int argc, char *argv[] )
 {
 
   /* Variables. */
