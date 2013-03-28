$NetBSD: patch-slots.c,v 1.1 2013/03/28 21:40:11 joerg Exp $

--- slots.c.orig	2013-03-28 19:21:20.000000000 +0000
+++ slots.c
@@ -535,8 +535,7 @@ Bool snaptogrid;
  * Note that if this code is changed, the similar code in SlotSetLocations
  * may need to be changed also.
  */
-SlotFree(winicon)
-WinIconFrame *winicon;
+void SlotFree(WinIconFrame *winicon)
 {
 	IconGrid	*iconGrid = winicon->core.client->scrInfo->iconGrid;
 
@@ -566,9 +565,7 @@ WinIconFrame *winicon;
  * in the new order.
  */
 /*ARGSUSED*/
-SlotSetLocations(dpy,iconGrid)
-Display *dpy;
-IconGrid *iconGrid;
+void SlotSetLocations(Display *dpy, IconGrid *iconGrid)
 {
 	List *lauto, *lpos;
 	List **l;
