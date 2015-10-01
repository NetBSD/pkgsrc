$NetBSD: patch-render_mitri.c,v 1.1 2015/10/01 12:55:09 tnn Exp $

http://cgit.freedesktop.org/~jeremyhu/xserver/log/?h=server-1.17-apple

--- render/mitri.c.orig	2014-02-05 03:08:58.000000000 +0000
+++ render/mitri.c
@@ -65,3 +65,64 @@ miTriangleBounds(int ntri, xTriangle * t
 {
     miPointFixedBounds(ntri * 3, (xPointFixed *) tris, bounds);
 }
+
+
+void
+miTriangles (CARD8	    op,
+	     PicturePtr	    pSrc,
+	     PicturePtr	    pDst,
+	     PictFormatPtr  maskFormat,
+	     INT16	    xSrc,
+	     INT16	    ySrc,
+	     int	    ntri,
+	     xTriangle	    *tris)
+{
+    ScreenPtr		pScreen = pDst->pDrawable->pScreen;
+    PictureScreenPtr    ps = GetPictureScreen(pScreen);
+    
+    /*
+     * Check for solid alpha add
+     */
+    if (op == PictOpAdd && miIsSolidAlpha (pSrc))
+    {
+	(*ps->AddTriangles) (pDst, 0, 0, ntri, tris);
+    }
+    else if (maskFormat)
+    {
+	BoxRec		bounds;
+	PicturePtr	pPicture;
+	INT16		xDst, yDst;
+	INT16		xRel, yRel;
+	
+	xDst = tris[0].p1.x >> 16;
+	yDst = tris[0].p1.y >> 16;
+
+	miTriangleBounds (ntri, tris, &bounds);
+	if (bounds.x2 <= bounds.x1 || bounds.y2 <= bounds.y1)
+	    return;
+	pPicture = miCreateAlphaPicture (pScreen, pDst, maskFormat,
+					 bounds.x2 - bounds.x1,
+					 bounds.y2 - bounds.y1);
+	if (!pPicture)
+	    return;
+	(*ps->AddTriangles) (pPicture, -bounds.x1, -bounds.y1, ntri, tris);
+	
+	xRel = bounds.x1 + xSrc - xDst;
+	yRel = bounds.y1 + ySrc - yDst;
+	CompositePicture (op, pSrc, pPicture, pDst,
+			  xRel, yRel, 0, 0, bounds.x1, bounds.y1,
+			  bounds.x2 - bounds.x1, bounds.y2 - bounds.y1);
+	FreePicture (pPicture, 0);
+    }
+    else
+    {
+	if (pDst->polyEdge == PolyEdgeSharp)
+	    maskFormat = PictureMatchFormat (pScreen, 1, PICT_a1);
+	else
+	    maskFormat = PictureMatchFormat (pScreen, 8, PICT_a8);
+	
+	for (; ntri; ntri--, tris++)
+	    miTriangles (op, pSrc, pDst, maskFormat, xSrc, ySrc, 1, tris);
+    }
+}
+
