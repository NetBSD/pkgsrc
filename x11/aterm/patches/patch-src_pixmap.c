$NetBSD: patch-src_pixmap.c,v 1.1 2016/05/01 19:56:40 dholland Exp $

Silence some sign-mismatch warnings.

--- src/pixmap.c~	2005-06-21 20:08:16.000000000 +0000
+++ src/pixmap.c
@@ -83,19 +83,20 @@ ValidatePixmap (Pixmap p, int bSetHandle
     /* we need to check if pixmap is still valid */
 	Window root;
     int junk;
+    unsigned ujunk;
 	if (bSetHandler)
 		oldXErrorHandler = XSetErrorHandler (pixmap_error_handler);
 
     if (bTransparent)
 	    p = GetRootPixmap (None);
 	if (!pWidth)
-  		pWidth = &junk;
+  		pWidth = &ujunk;
     if (!pHeight)
-	    pHeight = &junk;
+	    pHeight = &ujunk;
 
     if (p != None)
 	{
-  		if (!XGetGeometry (dpy, p, &root, &junk, &junk, pWidth, pHeight, &junk, &junk))
+  		if (!XGetGeometry (dpy, p, &root, &junk, &junk, pWidth, pHeight, &ujunk, &junk))
 			p = None;
     }
 	if(bSetHandler)
