$NetBSD: patch-tools_SigHandler.c,v 1.1 2023/01/22 20:08:17 vins Exp $

Avoid use of obsolete 'union wait *'.

--- tools/SigHandler.c.orig	1995-02-18 13:32:44.000000000 +0000
+++ tools/SigHandler.c
@@ -221,13 +221,7 @@ static void
   /* Variables. */
   int  index;
   int  pid;
-
-#if defined(_POSIX_SOURCE) || defined(_INCLUDE_POSIX_SOURCE)
   int  status;
-#else
-  union wait  status;
-#endif
-
 
   /* Code. */
 
