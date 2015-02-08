$NetBSD: patch-src_transparent.c,v 1.1 2015/02/08 18:12:49 tnn Exp $

Fix strict aligment SIGBUS

--- src/transparent.c.orig	2008-02-17 22:04:50.000000000 +0000
+++ src/transparent.c
@@ -56,7 +56,7 @@ rxvt_set_opacity (rxvt_t* r)
     Window	    wintree[PARENT_NUMBER];
     Window	    root;
     Window*	    list;
-    CARD32	    opacity;
+    CARD64	    opacity;
 
 
     /* do not set opacity */
@@ -71,7 +71,7 @@ rxvt_set_opacity (rxvt_t* r)
     XSetWindowBackground(r->Xdisplay, r->TermWin.parent, VTBG(r,0) );
 #endif
 
-    opacity = (CARD32) (r->TermWin.opacity * (0xffffffff / 100));
+    opacity = (CARD64) (r->TermWin.opacity * (0xffffffff / 100));
 
     /*
     ** look for parent tree of top level window because the window
