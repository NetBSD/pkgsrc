$NetBSD: patch-src_utils.cpp,v 1.1 2020/05/14 18:57:58 joerg Exp $

--- src/utils.cpp.orig	2020-05-10 22:10:06.527093091 +0000
+++ src/utils.cpp
@@ -382,11 +382,11 @@ void set_window_double_border(Display *d
 
     XRectangle rectangles[] =
     {
-        { width, 0, ibw, height + ibw },
-        { full_width - ibw, 0, ibw, height + ibw },
-        { 0, height, width + ibw, ibw },
-        { 0, full_height - ibw, width + ibw, ibw },
-        { full_width - ibw, full_height - ibw, ibw, ibw }
+        { (short)width, 0, (unsigned short)ibw, (unsigned short)(height + ibw) },
+        { (short)(full_width - ibw), 0, (unsigned short)ibw, (unsigned short)(height + ibw) },
+        { 0, (short)height, (unsigned short)(width + ibw), (unsigned short)ibw },
+        { 0, (short)(full_height - ibw), (unsigned short)(width + ibw), (unsigned short)ibw },
+        { (short)(full_width - ibw), (short)(full_height - ibw), (unsigned short)ibw, (unsigned short)ibw }
     };
 
     Pixmap pix = XCreatePixmap(dpy, win, full_width, full_height, depth);
