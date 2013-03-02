$NetBSD: patch-util.c,v 1.1 2013/03/02 17:54:53 joerg Exp $

--- util.c.orig	2013-03-01 13:20:30.000000000 +0000
+++ util.c
@@ -36,6 +36,9 @@
 
 #include <stdio.h>
 
+void recolor_cursor (Cursor cursor, unsigned long fg, unsigned long bg);
+void CopyWait(TScreen *screen);
+
 static void horizontal_copy_area();
 static void vertical_copy_area();
 
@@ -165,9 +168,7 @@ register TScreen *screen;
  * All done within the scrolling region, of course. 
  * requires: amount > 0
  */
-Scroll(screen, amount)
-register TScreen *screen;
-register int amount;
+void Scroll(TScreen *screen, int amount)
 {
 	register int i = screen->bot_marg - screen->top_marg + 1;
 	register int shift;
@@ -336,9 +337,7 @@ register int amount;
  * inserts n blank lines at the cursor's position.  Lines above the
  * bottom margin are lost.
  */
-InsertLine (screen, n)
-register TScreen *screen;
-register int n;
+void InsertLine (TScreen *screen, int n)
 {
 	register int i;
 	register int shift;
@@ -397,9 +396,7 @@ register int n;
  * If cursor not in scrolling region, returns.  Else, deletes n lines
  * at the cursor's position, lines added at bottom margin are blank.
  */
-DeleteLine(screen, n)
-register TScreen *screen;
-register int n;
+void DeleteLine(TScreen *screen, int n)
 {
 	register int i;
 	register int shift;
@@ -805,8 +802,7 @@ register TScreen *screen;
 	ClearBufRows (screen, 0, screen->max_row);
 }
 
-CopyWait(screen)
-register TScreen *screen;
+void CopyWait(TScreen *screen)
 {
 	XEvent reply;
 	XEvent *rep = &reply;
@@ -1144,9 +1140,7 @@ ReverseVideo (termw)
 }
 
 
-recolor_cursor (cursor, fg, bg)
-    Cursor cursor;			/* X cursor ID to set */
-    unsigned long fg, bg;		/* pixel indexes to look up */
+void recolor_cursor (Cursor cursor, unsigned long fg, unsigned long bg)
 {
     register TScreen *screen = &term->screen;
     register Display *dpy = screen->display;
