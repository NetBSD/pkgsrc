$NetBSD: patch-kwin_effects_mousemark_mousemark.cpp,v 1.2 2013/11/07 13:35:56 markd Exp $

Avoid "ambiguous call to overloaded function".

--- kwin/effects/mousemark/mousemark.cpp.orig	2013-05-03 04:36:45.570118483 +0000
+++ kwin/effects/mousemark/mousemark.cpp
@@ -89,7 +89,7 @@ void MouseMarkEffect::addRect(const QPoi
     r->height = qAbs(p1.y()-p2.y()) + 1 + width_2;
     // fast move -> large rect, <strike>tess...</strike> interpolate a line
     if (r->width > 3*width/2 && r->height > 3*width/2) {
-        const int n = sqrt(r->width*r->width + r->height*r->height) / width;
+        const int n = sqrt((float) (r->width*r->width + r->height*r->height)) / width;
         xcb_rectangle_t *rects = new xcb_rectangle_t[n-1];
         const int w = p1.x() < p2.x() ? r->width : -r->width;
         const int h = p1.y() < p2.y() ? r->height : -r->height;
