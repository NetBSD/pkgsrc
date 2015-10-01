$NetBSD: patch-render_mipict.h,v 1.1 2015/10/01 12:55:09 tnn Exp $

http://cgit.freedesktop.org/~jeremyhu/xserver/log/?h=server-1.17-apple

--- render/mipict.h.orig	2015-01-17 23:42:52.000000000 +0000
+++ render/mipict.h
@@ -122,6 +122,16 @@ miCompositeRects(CARD8 op,
                  xRenderColor * color, int nRect, xRectangle *rects);
 
 extern _X_EXPORT void
+miTriangles (CARD8	    op,
+	     PicturePtr	    pSrc,
+	     PicturePtr	    pDst,
+	     PictFormatPtr  maskFormat,
+	     INT16	    xSrc,
+	     INT16	    ySrc,
+	     int	    ntri,
+	     xTriangle	    *tris);
+
+extern _X_EXPORT void
 
 miTriStrip(CARD8 op,
            PicturePtr pSrc,
@@ -137,10 +147,27 @@ miTriFan(CARD8 op,
          PictFormatPtr maskFormat,
          INT16 xSrc, INT16 ySrc, int npoints, xPointFixed * points);
 
+extern _X_EXPORT PicturePtr
+miCreateAlphaPicture (ScreenPtr	    pScreen, 
+		      PicturePtr    pDst,
+		      PictFormatPtr pPictFormat,
+		      CARD16	    width,
+		      CARD16	    height);
+
 extern _X_EXPORT void
  miTrapezoidBounds(int ntrap, xTrapezoid * traps, BoxPtr box);
 
 extern _X_EXPORT void
+miTrapezoids (CARD8        op,
+             PicturePtr    pSrc,
+             PicturePtr    pDst,
+             PictFormatPtr maskFormat,
+             INT16         xSrc,
+             INT16         ySrc,
+             int           ntrap,
+             xTrapezoid    *traps);
+
+extern _X_EXPORT void
  miPointFixedBounds(int npoint, xPointFixed * points, BoxPtr bounds);
 
 extern _X_EXPORT void
