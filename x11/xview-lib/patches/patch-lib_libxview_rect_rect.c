$NetBSD: patch-lib_libxview_rect_rect.c,v 1.1 2012/11/16 00:29:40 joerg Exp $

--- lib/libxview/rect/rect.c.orig	2012-11-14 15:07:09.000000000 +0000
+++ lib/libxview/rect/rect.c
@@ -24,8 +24,7 @@ static char     sccsid[] = "@(#)rect.c 2
 /*
  * Rect geometry functions
  */
-rect_intersection(r1, r2, r)
-    register struct rect *r1, *r2, *r;
+void rect_intersection(Rect *r1, Rect *r2, Rect *r)
 {
     r->r_left = MAX(r1->r_left, r2->r_left);
     r->r_top = MAX(r1->r_top, r2->r_top);
