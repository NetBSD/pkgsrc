$NetBSD: patch-kwin_effects_mousemark_mousemark.cpp,v 1.1 2013/06/22 22:39:10 jperkin Exp $

Avoid "ambiguous call to overloaded function".

--- kwin/effects/mousemark/mousemark.cpp.orig	2013-05-03 04:36:45.570118483 +0000
+++ kwin/effects/mousemark/mousemark.cpp
@@ -84,7 +84,7 @@ void MouseMarkEffect::addRect(const QPoi
     r->height = qAbs(p1.y()-p2.y()) + 1 + width_2;
     // fast move -> large rect, <strike>tess...</strike> interpolate a line
     if (r->width > 3*width/2 && r->height > 3*width/2) {
-        const int n = sqrt(r->width*r->width + r->height*r->height) / width;
+        const int n = sqrt((float)(r->width*r->width + r->height*r->height)) / width;
         XRectangle *rects = new XRectangle[n-1];
         const int w = p1.x() < p2.x() ? r->width : -r->width;
         const int h = p1.y() < p2.y() ? r->height : -r->height;
