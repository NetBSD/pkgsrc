$NetBSD: patch-exa_exa__render.c,v 1.1 2015/04/03 09:46:18 tnn Exp $

Fix CVE-2013-6424 using
http://lists.x.org/archives/xorg-devel/2013-October/037996.html

--- exa/exa_render.c.orig	2012-05-17 17:09:02.000000000 +0000
+++ exa/exa_render.c
@@ -1141,7 +1141,8 @@ exaTrapezoids(CARD8 op, PicturePtr pSrc,
 
         exaPrepareAccess(pPicture->pDrawable, EXA_PREPARE_DEST);
         for (; ntrap; ntrap--, traps++)
-            (*ps->RasterizeTrapezoid) (pPicture, traps, -bounds.x1, -bounds.y1);
+            if (xTrapezoidValid(traps))
+                (*ps->RasterizeTrapezoid) (pPicture, traps, -bounds.x1, -bounds.y1);
         exaFinishAccess(pPicture->pDrawable, EXA_PREPARE_DEST);
 
         xRel = bounds.x1 + xSrc - xDst;
