$NetBSD: patch-src_decoration.cpp,v 1.1 2020/05/14 18:57:58 joerg Exp $

--- src/decoration.cpp.orig	2020-05-10 21:59:55.356580498 +0000
+++ src/decoration.cpp
@@ -526,10 +526,10 @@ void decoration_redraw_pixmap(struct HSC
     if (iw > 0) {
         /* fill rectangles because drawing does not work */
         XRectangle rects[] = {
-            { inner.x - iw, inner.y - iw, inner.width + 2*iw, iw }, /* top */
-            { inner.x - iw, inner.y, iw, inner.height },  /* left */
-            { inner.x + inner.width, inner.y, iw, inner.height }, /* right */
-            { inner.x - iw, inner.y + inner.height, inner.width + 2*iw, iw }, /* bottom */
+            { (short)(inner.x - iw), (short)(inner.y - iw), (unsigned short)(inner.width + 2*iw), (unsigned short)iw }, /* top */
+            { (short)(inner.x - iw), (short)(inner.y), (unsigned short)iw, (unsigned short)inner.height },  /* left */
+            { (short)(inner.x + inner.width), (short)(inner.y), (unsigned short)iw, (unsigned short)inner.height }, /* right */
+            { (short)(inner.x - iw), (short)(inner.y + inner.height), (unsigned short)(inner.width + 2*iw), (unsigned short)iw }, /* bottom */
         };
         XSetForeground(g_display, gc, get_client_color(client, s.inner_color));
         XFillRectangles(g_display, pix, gc, rects, LENGTH(rects));
@@ -542,10 +542,10 @@ void decoration_redraw_pixmap(struct HSC
     if (ow > 0) {
         ow = MIN(ow, (outer.height+1) / 2);
         XRectangle rects[] = {
-            { 0, 0, outer.width, ow }, /* top */
-            { 0, ow, ow, outer.height - 2*ow }, /* left */
-            { outer.width-ow, ow, ow, outer.height - 2*ow }, /* right */
-            { 0, outer.height - ow, outer.width, ow }, /* bottom */
+            { 0, 0, (unsigned short)outer.width, (unsigned short)ow }, /* top */
+            { 0, (short)ow, (unsigned short)ow, (unsigned short)(outer.height - 2*ow) }, /* left */
+            { (short)(outer.width-ow), (short)ow, (unsigned short)ow, (unsigned short)(outer.height - 2*ow) }, /* right */
+            { 0, (short)(outer.height - ow), (unsigned short)outer.width, (unsigned short)ow }, /* bottom */
         };
         XSetForeground(g_display, gc, get_client_color(client, s.outer_color));
         XFillRectangles(g_display, pix, gc, rects, LENGTH(rects));
