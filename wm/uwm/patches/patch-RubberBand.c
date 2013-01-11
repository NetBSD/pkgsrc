$NetBSD: patch-RubberBand.c,v 1.1 2013/01/11 23:36:16 joerg Exp $

--- RubberBand.c.orig	2013-01-11 14:54:30.000000000 +0000
+++ RubberBand.c
@@ -50,12 +50,7 @@
 #define BW	PBorderWidth		/* pop-up window border width */
 #define IBW	PPadding		/* internal border width for pop-up */
 
-AskUser(dpy, scr, window, x, y, width, height, hints)
-	Display *dpy;
-	int scr;
-	Window window;
-	int *x, *y, *width, *height;
-	XSizeHints *hints;
+void AskUser(Display *dpy, int scr, Window window, int *x, int *y, int *width, int *height, XSizeHints *hints)
 	{
 	/* XFontStruct *pfont; */
 #define pfont	PFontInfo		/* text font for pop-up */
