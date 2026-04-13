$NetBSD: patch-xcursor_xcursor.c,v 1.1 2026/04/13 17:20:09 kikadf Exp $

* Fix cursor pathes

--- xcursor/xcursor.c.orig	2025-09-13 13:33:55.701973322 +0000
+++ xcursor/xcursor.c
@@ -486,11 +486,11 @@ xcursor_xc_file_load_images(FILE *file, 
  */
 
 #ifndef ICONDIR
-#define ICONDIR "/usr/X11R6/lib/X11/icons"
+#define ICONDIR "@X11BASE@/include/X11/pixmaps"
 #endif
 
 #ifndef XCURSORPATH
-#define XCURSORPATH "~/.icons:/usr/share/icons:/usr/share/pixmaps:~/.cursors:/usr/share/cursors/xorg-x11:"ICONDIR
+#define XCURSORPATH "~/.icons:@PREFIX@/share/icons:~/.cursors:"ICONDIR
 #endif
 
 #define XDG_DATA_HOME_FALLBACK "~/.local/share"
