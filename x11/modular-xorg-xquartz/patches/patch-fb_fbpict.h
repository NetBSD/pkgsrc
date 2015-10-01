$NetBSD: patch-fb_fbpict.h,v 1.1 2015/10/01 12:55:09 tnn Exp $

http://cgit.freedesktop.org/~jeremyhu/xserver/log/?h=server-1.17-apple

--- fb/fbpict.h.orig	2014-11-17 05:51:18.000000000 +0000
+++ fb/fbpict.h
@@ -65,20 +65,11 @@ fbTrapezoids(CARD8 op,
              INT16 xSrc, INT16 ySrc, int ntrap, xTrapezoid * traps);
 
 extern _X_EXPORT void
+
 fbTriangles(CARD8 op,
             PicturePtr pSrc,
             PicturePtr pDst,
             PictFormatPtr maskFormat,
             INT16 xSrc, INT16 ySrc, int ntris, xTriangle * tris);
 
-extern _X_EXPORT void
-fbGlyphs(CARD8 op,
-	 PicturePtr pSrc,
-	 PicturePtr pDst,
-	 PictFormatPtr maskFormat,
-	 INT16 xSrc,
-	 INT16 ySrc, int nlist,
-	 GlyphListPtr list,
-	 GlyphPtr *glyphs);
-
 #endif                          /* _FBPICT_H_ */
