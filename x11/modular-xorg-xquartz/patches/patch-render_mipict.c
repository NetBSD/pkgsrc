$NetBSD: patch-render_mipict.c,v 1.1 2015/10/01 12:55:09 tnn Exp $

http://cgit.freedesktop.org/~jeremyhu/xserver/log/?h=server-1.17-apple

--- render/mipict.c.orig	2014-11-17 05:51:18.000000000 +0000
+++ render/mipict.c
@@ -575,8 +575,8 @@ miPictureInit(ScreenPtr pScreen, PictFor
     ps->Composite = 0;          /* requires DDX support */
     ps->Glyphs = miGlyphs;
     ps->CompositeRects = miCompositeRects;
-    ps->Trapezoids = 0;
-    ps->Triangles = 0;
+    ps->Trapezoids = miTrapezoids;
+    ps->Triangles = miTriangles;
 
     ps->RasterizeTrapezoid = 0; /* requires DDX support */
     ps->AddTraps = 0;           /* requires DDX support */
