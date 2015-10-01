$NetBSD: patch-render_mitrap.c,v 1.1 2015/10/01 12:55:09 tnn Exp $

http://cgit.freedesktop.org/~jeremyhu/xserver/log/?h=server-1.17-apple

--- render/mitrap.c.orig	2014-02-12 03:43:50.000000000 +0000
+++ render/mitrap.c
@@ -34,6 +34,55 @@
 #include "picturestr.h"
 #include "mipict.h"
 
+PicturePtr
+miCreateAlphaPicture (ScreenPtr	    pScreen, 
+		      PicturePtr    pDst,
+		      PictFormatPtr pPictFormat,
+		      CARD16	    width,
+		      CARD16	    height)
+{
+    PixmapPtr	    pPixmap;
+    PicturePtr	    pPicture;
+    GCPtr	    pGC;
+    int		    error;
+    xRectangle	    rect;
+
+    if (width > 32767 || height > 32767)
+	return 0;
+
+    if (!pPictFormat)
+    {
+	if (pDst->polyEdge == PolyEdgeSharp)
+	    pPictFormat = PictureMatchFormat (pScreen, 1, PICT_a1);
+	else
+	    pPictFormat = PictureMatchFormat (pScreen, 8, PICT_a8);
+	if (!pPictFormat)
+	    return 0;
+    }
+
+    pPixmap = (*pScreen->CreatePixmap) (pScreen, width, height, 
+					pPictFormat->depth, 0);
+    if (!pPixmap)
+	return 0;
+    pGC = GetScratchGC (pPixmap->drawable.depth, pScreen);
+    if (!pGC)
+    {
+	(*pScreen->DestroyPixmap) (pPixmap);
+	return 0;
+    }
+    ValidateGC (&pPixmap->drawable, pGC);
+    rect.x = 0;
+    rect.y = 0;
+    rect.width = width;
+    rect.height = height;
+    (*pGC->ops->PolyFillRect)(&pPixmap->drawable, pGC, 1, &rect);
+    FreeScratchGC (pGC);
+    pPicture = CreatePicture (0, &pPixmap->drawable, pPictFormat,
+			      0, 0, serverClient, &error);
+    (*pScreen->DestroyPixmap) (pPixmap);
+    return pPicture;
+}
+
 static xFixed
 miLineFixedX(xLineFixed * l, xFixed y, Bool ceil)
 {
@@ -79,3 +128,65 @@ miTrapezoidBounds(int ntrap, xTrapezoid 
             box->x2 = x2;
     }
 }
+
+
+void
+miTrapezoids (CARD8        op,
+             PicturePtr    pSrc,
+             PicturePtr    pDst,
+             PictFormatPtr maskFormat,
+             INT16         xSrc,
+             INT16         ySrc,
+             int           ntrap,
+             xTrapezoid    *traps)
+{
+    ScreenPtr          pScreen = pDst->pDrawable->pScreen;
+    PictureScreenPtr    ps = GetPictureScreen(pScreen);
+
+    /*
+     * Check for solid alpha add
+     */
+    if (op == PictOpAdd && miIsSolidAlpha (pSrc))
+    {
+       for (; ntrap; ntrap--, traps++)
+           (*ps->RasterizeTrapezoid) (pDst, traps, 0, 0);
+    } 
+    else if (maskFormat)
+    {
+       PicturePtr      pPicture;
+       BoxRec          bounds;
+       INT16           xDst, yDst;
+       INT16           xRel, yRel;
+       
+       xDst = traps[0].left.p1.x >> 16;
+       yDst = traps[0].left.p1.y >> 16;
+
+       miTrapezoidBounds (ntrap, traps, &bounds);
+       if (bounds.y1 >= bounds.y2 || bounds.x1 >= bounds.x2)
+           return;
+       pPicture = miCreateAlphaPicture (pScreen, pDst, maskFormat,
+                                        bounds.x2 - bounds.x1,
+                                        bounds.y2 - bounds.y1);
+       if (!pPicture)
+           return;
+       for (; ntrap; ntrap--, traps++)
+           (*ps->RasterizeTrapezoid) (pPicture, traps, 
+                                      -bounds.x1, -bounds.y1);
+       xRel = bounds.x1 + xSrc - xDst;
+       yRel = bounds.y1 + ySrc - yDst;
+       CompositePicture (op, pSrc, pPicture, pDst,
+                         xRel, yRel, 0, 0, bounds.x1, bounds.y1,
+                         bounds.x2 - bounds.x1,
+                         bounds.y2 - bounds.y1);
+       FreePicture (pPicture, 0);
+    }
+    else
+    {
+       if (pDst->polyEdge == PolyEdgeSharp)
+           maskFormat = PictureMatchFormat (pScreen, 1, PICT_a1);
+       else
+           maskFormat = PictureMatchFormat (pScreen, 8, PICT_a8);
+       for (; ntrap; ntrap--, traps++)
+           miTrapezoids (op, pSrc, pDst, maskFormat, xSrc, ySrc, 1, traps);
+    }
+}
