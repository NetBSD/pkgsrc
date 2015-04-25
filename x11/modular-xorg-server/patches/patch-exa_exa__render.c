$NetBSD: patch-exa_exa__render.c,v 1.2 2015/04/25 11:47:03 tnn Exp $

Fix CVE-2013-6424 using
http://lists.x.org/archives/xorg-devel/2013-October/037996.html

XXX why does upstream not have this patch?
XXX was it fixed differently or is it still unpatched?

--- exa/exa_render.c.orig	2015-01-17 23:42:52.000000000 +0000
+++ exa/exa_render.c
@@ -1141,7 +1141,8 @@ exaTrapezoids(CARD8 op, PicturePtr pSrc,
 
         exaPrepareAccess(pPicture->pDrawable, EXA_PREPARE_DEST);
         for (; ntrap; ntrap--, traps++)
-            (*ps->RasterizeTrapezoid) (pPicture, traps, -bounds.x1, -bounds.y1);
+            if (xTrapezoidValid(traps))
+                (*ps->RasterizeTrapezoid) (pPicture, traps, -bounds.x1, -bounds.y1);
         exaFinishAccess(pPicture->pDrawable, EXA_PREPARE_DEST);
 
         xRel = bounds.x1 + xSrc - xDst;
