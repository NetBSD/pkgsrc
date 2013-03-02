$NetBSD: patch-scrollbar.c,v 1.1 2013/03/02 17:54:53 joerg Exp $

--- scrollbar.c.orig	2013-03-01 13:19:28.000000000 +0000
+++ scrollbar.c
@@ -265,9 +265,7 @@ ResizeScrollBar(scrollWidget, x, y, heig
 	ScrollBarDrawThumb(scrollWidget);
 }
 
-WindowScroll(screen, top)
-	register TScreen *screen;
-	int top;
+void WindowScroll(TScreen *screen, int top)
 {
 	register int i, lines;
 	register int scrolltop, scrollheight, refreshtop;
@@ -317,9 +315,7 @@ WindowScroll(screen, top)
 }
 
 
-ScrollBarOn (xw, init, doalloc)
-    XtermWidget xw;
-    int init, doalloc;
+void ScrollBarOn (XtermWidget xw, int init, int doalloc)
 {
 	register TScreen *screen = &xw->screen;
 	register int border = 2 * screen->border;
@@ -404,8 +400,7 @@ ScrollBarOn (xw, init, doalloc)
 	}
 }
 
-ScrollBarOff(screen)
-	register TScreen *screen;
+void ScrollBarOff(TScreen *screen)
 {
 	if(!screen->scrollbar)
 		return;
