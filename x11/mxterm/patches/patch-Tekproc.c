$NetBSD: patch-Tekproc.c,v 1.1 2013/07/19 12:58:20 joerg Exp $

--- Tekproc.c.orig	2013-07-19 10:49:52.000000000 +0000
+++ Tekproc.c
@@ -354,7 +354,7 @@ int TekInit (void)
 			XtNright,	XawChainRight,
 			XtNbottom,	XawChainBottom,
 #endif
-			0);
+			(void *)0);
     }
     return (!Tfailed);
 }
