$NetBSD: patch-space_dapp.c,v 1.1.1.1 2009/07/07 12:36:31 sborrill Exp $

Stop coredump if DISPLAY not set

--- space_dapp.c.orig	2009-07-07 13:28:13.000000000 +0100
+++ space_dapp.c	2009-07-07 13:29:06.000000000 +0100
@@ -92,7 +92,10 @@
 
 
     dpy = XOpenDisplay(NULL);
-    assert(dpy != NULL);
+    if (dpy == NULL) {
+      fprintf(stderr, "DISPLAY not set\n");
+      exit(1);
+    }
 
     screen = DefaultScreen(dpy);
     root_win = RootWindow(dpy, screen);
