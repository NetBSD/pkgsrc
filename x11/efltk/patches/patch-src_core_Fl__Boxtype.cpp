$NetBSD: patch-src_core_Fl__Boxtype.cpp,v 1.1 2018/04/20 01:36:00 christos Exp $

Avoid gcc-6 narrowing warnings

--- src/core/Fl_Boxtype.cpp.orig	2003-04-24 09:58:36.000000000 -0400
+++ src/core/Fl_Boxtype.cpp	2018-04-19 21:28:39.973007945 -0400
@@ -49,14 +49,14 @@
 #ifndef _WIN32
     // X version uses stipple pattern because there seem to be too many
     // servers with bugs when drawing dotted lines:
-    static const char pattern[] = {0xAA,0x55,0xAA,0x55,0xAA,0x55,0xAA,0x55,0xAA};
+    static const unsigned char pattern[] = {0xAA,0x55,0xAA,0x55,0xAA,0x55,0xAA,0x55,0xAA};
     static Pixmap evenstipple, oddstipple;
     if (!evenstipple)
     {
 		// Init stipple bitmaps
         Window root = RootWindow(fl_display, fl_screen);
-        evenstipple = XCreateBitmapFromData(fl_display, root, pattern, 8, 8);
-        oddstipple  = XCreateBitmapFromData(fl_display, root, pattern+1, 8, 8);
+        evenstipple = XCreateBitmapFromData(fl_display, root, (const char *)pattern, 8, 8);
+        oddstipple  = XCreateBitmapFromData(fl_display, root, (const char *)pattern+1, 8, 8);
     }
     int xx = x; int yy = y; fl_transform(xx,yy);
     XSetStipple(fl_display, fl_gc, (xx+yy-x-y)&1 ? oddstipple : evenstipple);
