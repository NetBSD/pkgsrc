$NetBSD: patch-xwindow_fb_x.h,v 1.2 2014/07/21 15:42:56 tsutsui Exp $

- pull post 3.3.7 fixes:
http://sourceforge.net/projects/mlterm/files/01release/mlterm-3.3.7/mlterm-3.3.7-fixes.patch/download
 * x.h: KS_Print -> KS_Print_Screen

--- xwindow/fb/x.h.orig	2014-07-05 21:40:41.000000000 +0000
+++ xwindow/fb/x.h
@@ -309,7 +309,7 @@ typedef int XFontSet ;	/* dummy */
 #define XK_Right	KS_Right
 #define XK_Down		KS_Down
 #define XK_Select	KS_Select
-#define XK_Print	KS_Print
+#define XK_Print	KS_Print_Screen
 #define XK_Execute	KS_Execute
 #define XK_Insert	KS_Insert
 #define XK_Delete	KS_Delete
