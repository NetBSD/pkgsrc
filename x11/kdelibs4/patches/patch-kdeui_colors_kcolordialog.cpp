$NetBSD: patch-kdeui_colors_kcolordialog.cpp,v 1.1 2011/09/27 10:48:20 markd Exp $

Find rgb.txt in pkgsrc or native

--- kdeui/colors/kcolordialog.cpp.orig	2010-05-27 17:26:18.000000000 +0000
+++ kdeui/colors/kcolordialog.cpp
@@ -627,6 +627,8 @@ static const char * const *namedColorFil
 #ifdef X11_RGBFILE
         X11_RGBFILE, 0,
 #endif
+        "@X11BASE@/share/X11/rgb.txt", 0,
+        "@X11BASE@/lib/X11/rgb.txt", 0,
         "/usr/share/X11/rgb.txt", 0,
         "/usr/X11R6/lib/X11/rgb.txt", 0,
         "/usr/openwin/lib/X11/rgb.txt", 0, // for Solaris.
