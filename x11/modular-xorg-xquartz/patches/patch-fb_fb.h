$NetBSD: patch-fb_fb.h,v 1.1 2015/10/01 12:55:09 tnn Exp $

http://cgit.freedesktop.org/~jeremyhu/xserver/log/?h=server-1.17-apple

--- fb/fb.h.orig	2014-11-17 05:51:18.000000000 +0000
+++ fb/fb.h
@@ -1116,9 +1116,6 @@ extern _X_EXPORT void
 extern _X_EXPORT Bool
  fbPictureInit(ScreenPtr pScreen, PictFormatPtr formats, int nformats);
 
-extern _X_EXPORT void
-fbDestroyGlyphCache(void);
-
 /*
  * fbpixmap.c
  */
@@ -1326,8 +1323,7 @@ fbFillRegionSolid(DrawablePtr pDrawable,
                   RegionPtr pRegion, FbBits and, FbBits xor);
 
 extern _X_EXPORT pixman_image_t *image_from_pict(PicturePtr pict,
-                                                 Bool has_clip,
-                                                 int *xoff, int *yoff);
+                                                 Bool has_clip);
 
 extern _X_EXPORT void free_pixman_pict(PicturePtr, pixman_image_t *);
 
