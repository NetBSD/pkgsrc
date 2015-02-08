$NetBSD: patch-src_init.c,v 1.1 2015/02/08 18:12:49 tnn Exp $

Fix strict alignment SIGBUS

--- src/init.c.orig	2008-06-13 19:08:13.000000000 +0000
+++ src/init.c
@@ -3239,7 +3239,7 @@ rxvt_create_show_windows( rxvt_t *r, int
     XGCValues		    gcvalue;
     unsigned long	    gcmask;
 #ifndef NO_FRILLS
-    CARD32		    pid = (CARD32) getpid ();
+    CARD64		    pid = (CARD64) getpid ();
 #endif
 #ifdef TRANSPARENT
     register int	    i;
