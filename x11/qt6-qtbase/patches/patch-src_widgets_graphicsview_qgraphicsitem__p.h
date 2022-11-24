$NetBSD: patch-src_widgets_graphicsview_qgraphicsitem__p.h,v 1.1 2022/11/24 11:11:38 nros Exp $

--- src/widgets/graphicsview/qgraphicsitem_p.h.orig	2013-11-27 01:01:12.000000000 +0000
+++ src/widgets/graphicsview/qgraphicsitem_p.h
@@ -761,7 +761,7 @@ inline bool qt_closestItemFirst(const QG
     // item1Ancestor is now at the same level as item2Ancestor, but not the same.
     const QGraphicsItem *p1 = t1;
     const QGraphicsItem *p2 = t2;
-    while (t1 && t1 != t2) {
+    while (t1 && t2 && t1 != t2) {
         p1 = t1;
         p2 = t2;
         t1 = t1->d_ptr->parent;
