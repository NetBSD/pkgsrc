$NetBSD: patch-fb_fbpict.c,v 1.1 2015/10/01 12:55:09 tnn Exp $

http://cgit.freedesktop.org/~jeremyhu/xserver/log/?h=server-1.17-apple

--- fb/fbpict.c.orig	2015-01-17 23:42:52.000000000 +0000
+++ fb/fbpict.c
@@ -46,23 +46,18 @@ fbComposite(CARD8 op,
             INT16 yMask, INT16 xDst, INT16 yDst, CARD16 width, CARD16 height)
 {
     pixman_image_t *src, *mask, *dest;
-    int src_xoff, src_yoff;
-    int msk_xoff, msk_yoff;
-    int dst_xoff, dst_yoff;
-
     miCompositeSourceValidate(pSrc);
     if (pMask)
         miCompositeSourceValidate(pMask);
 
-    src = image_from_pict(pSrc, FALSE, &src_xoff, &src_yoff);
-    mask = image_from_pict(pMask, FALSE, &msk_xoff, &msk_yoff);
-    dest = image_from_pict(pDst, TRUE, &dst_xoff, &dst_yoff);
+    src = image_from_pict(pSrc, TRUE);
+    mask = image_from_pict(pMask, TRUE);
+    dest = image_from_pict(pDst, TRUE);
 
     if (src && dest && !(pMask && !mask)) {
         pixman_image_composite(op, src, mask, dest,
-                               xSrc + src_xoff, ySrc + src_yoff,
-                               xMask + msk_xoff, yMask + msk_yoff,
-                               xDst + dst_xoff, yDst + dst_yoff, width, height);
+                               xSrc, ySrc, xMask, yMask, xDst, yDst,
+                               width, height);
     }
 
     free_pixman_pict(pSrc, src);
@@ -70,152 +65,6 @@ fbComposite(CARD8 op,
     free_pixman_pict(pDst, dest);
 }
 
-static pixman_glyph_cache_t *glyphCache;
-
-void
-fbDestroyGlyphCache(void)
-{
-    if (glyphCache)
-    {
-	pixman_glyph_cache_destroy (glyphCache);
-	glyphCache = NULL;
-    }
-}
-
-static void
-fbUnrealizeGlyph(ScreenPtr pScreen,
-		 GlyphPtr pGlyph)
-{
-    if (glyphCache)
-	pixman_glyph_cache_remove (glyphCache, pGlyph, NULL);
-}
-
-void
-fbGlyphs(CARD8 op,
-	 PicturePtr pSrc,
-	 PicturePtr pDst,
-	 PictFormatPtr maskFormat,
-	 INT16 xSrc,
-	 INT16 ySrc, int nlist,
-	 GlyphListPtr list,
-	 GlyphPtr *glyphs)
-{
-#define N_STACK_GLYPHS 512
-    ScreenPtr pScreen = pDst->pDrawable->pScreen;
-    pixman_glyph_t stack_glyphs[N_STACK_GLYPHS];
-    pixman_glyph_t *pglyphs = stack_glyphs;
-    pixman_image_t *srcImage, *dstImage;
-    int srcXoff, srcYoff, dstXoff, dstYoff;
-    GlyphPtr glyph;
-    int n_glyphs;
-    int x, y;
-    int i, n;
-    int xDst = list->xOff, yDst = list->yOff;
-
-    miCompositeSourceValidate(pSrc);
-
-    n_glyphs = 0;
-    for (i = 0; i < nlist; ++i)
-	n_glyphs += list[i].len;
-
-    if (!glyphCache)
-	glyphCache = pixman_glyph_cache_create();
-
-    pixman_glyph_cache_freeze (glyphCache);
-
-    if (n_glyphs > N_STACK_GLYPHS) {
-	if (!(pglyphs = malloc (n_glyphs * sizeof (pixman_glyph_t))))
-	    goto out;
-    }
-
-    i = 0;
-    x = y = 0;
-    while (nlist--) {
-        x += list->xOff;
-        y += list->yOff;
-        n = list->len;
-        while (n--) {
-	    const void *g;
-
-            glyph = *glyphs++;
-
-	    if (!(g = pixman_glyph_cache_lookup (glyphCache, glyph, NULL))) {
-		pixman_image_t *glyphImage;
-		PicturePtr pPicture;
-		int xoff, yoff;
-
-		pPicture = GetGlyphPicture(glyph, pScreen);
-		if (!pPicture) {
-		    n_glyphs--;
-		    goto next;
-		}
-
-		if (!(glyphImage = image_from_pict(pPicture, FALSE, &xoff, &yoff)))
-		    goto out;
-
-		g = pixman_glyph_cache_insert(glyphCache, glyph, NULL,
-					      glyph->info.x,
-					      glyph->info.y,
-					      glyphImage);
-
-		free_pixman_pict(pPicture, glyphImage);
-
-		if (!g)
-		    goto out;
-	    }
-
-	    pglyphs[i].x = x;
-	    pglyphs[i].y = y;
-	    pglyphs[i].glyph = g;
-	    i++;
-
-	next:
-            x += glyph->info.xOff;
-            y += glyph->info.yOff;
-	}
-	list++;
-    }
-
-    if (!(srcImage = image_from_pict(pSrc, FALSE, &srcXoff, &srcYoff)))
-	goto out;
-
-    if (!(dstImage = image_from_pict(pDst, TRUE, &dstXoff, &dstYoff)))
-	goto out_free_src;
-
-    if (maskFormat) {
-	pixman_format_code_t format;
-	pixman_box32_t extents;
-
-	format = maskFormat->format | (maskFormat->depth << 24);
-
-	pixman_glyph_get_extents(glyphCache, n_glyphs, pglyphs, &extents);
-
-	pixman_composite_glyphs(op, srcImage, dstImage, format,
-				xSrc + srcXoff + extents.x1 - xDst, ySrc + srcYoff + extents.y1 - yDst,
-				extents.x1, extents.y1,
-				extents.x1 + dstXoff, extents.y1 + dstYoff,
-				extents.x2 - extents.x1,
-				extents.y2 - extents.y1,
-				glyphCache, n_glyphs, pglyphs);
-    }
-    else {
-	pixman_composite_glyphs_no_mask(op, srcImage, dstImage,
-					xSrc + srcXoff - xDst, ySrc + srcYoff - yDst,
-					dstXoff, dstYoff,
-					glyphCache, n_glyphs, pglyphs);
-    }
-
-    free_pixman_pict(pDst, dstImage);
-
-out_free_src:
-    free_pixman_pict(pSrc, srcImage);
-
-out:
-    pixman_glyph_cache_thaw(glyphCache);
-    if (pglyphs != stack_glyphs)
-	free(pglyphs);
-}
-
 static pixman_image_t *
 create_solid_fill_image(PicturePtr pict)
 {
@@ -289,20 +138,22 @@ create_conical_gradient_image(PictGradie
 }
 
 static pixman_image_t *
-create_bits_picture(PicturePtr pict, Bool has_clip, int *xoff, int *yoff)
+create_bits_picture(PicturePtr pict, Bool has_clip)
 {
-    PixmapPtr pixmap;
     FbBits *bits;
     FbStride stride;
-    int bpp;
+    int bpp, xoff, yoff;
     pixman_image_t *image;
 
-    fbGetDrawablePixmap(pict->pDrawable, pixmap, *xoff, *yoff);
-    fbGetPixmapBitsData(pixmap, bits, stride, bpp);
+    fbGetDrawable (pict->pDrawable, bits, stride, bpp, xoff, yoff);
+
+    bits = (FbBits*)((CARD8*)bits +
+                     (pict->pDrawable->y + yoff) * stride * sizeof(FbBits) +
+                     (pict->pDrawable->x + xoff) * (bpp / 8));
 
     image = pixman_image_create_bits((pixman_format_code_t) pict->format,
-                                     pixmap->drawable.width,
-                                     pixmap->drawable.height, (uint32_t *) bits,
+                                     pict->pDrawable->width,
+                                     pict->pDrawable->height, (uint32_t *) bits,
                                      stride * sizeof(FbStride));
 
     if (!image)
@@ -321,56 +172,30 @@ create_bits_picture(PicturePtr pict, Boo
         if (pict->clientClip)
             pixman_image_set_has_client_clip(image, TRUE);
 
-        if (*xoff || *yoff)
-            pixman_region_translate(pict->pCompositeClip, *xoff, *yoff);
+        pixman_region_translate (pict->pCompositeClip, - pict->pDrawable->x, - pict->pDrawable->y);
 
         pixman_image_set_clip_region(image, pict->pCompositeClip);
 
-        if (*xoff || *yoff)
-            pixman_region_translate(pict->pCompositeClip, -*xoff, -*yoff);
+        pixman_region_translate (pict->pCompositeClip, pict->pDrawable->x, pict->pDrawable->y);
     }
 
     /* Indexed table */
     if (pict->pFormat->index.devPrivate)
         pixman_image_set_indexed(image, pict->pFormat->index.devPrivate);
 
-    /* Add in drawable origin to position within the image */
-    *xoff += pict->pDrawable->x;
-    *yoff += pict->pDrawable->y;
-
     return image;
 }
 
 static pixman_image_t *image_from_pict_internal(PicturePtr pict, Bool has_clip,
-                                                int *xoff, int *yoff,
                                                 Bool is_alpha_map);
 
 static void
-set_image_properties(pixman_image_t * image, PicturePtr pict, Bool has_clip,
-                     int *xoff, int *yoff, Bool is_alpha_map)
+set_image_properties(pixman_image_t * image, PicturePtr pict, Bool is_alpha_map)
 {
     pixman_repeat_t repeat;
     pixman_filter_t filter;
 
     if (pict->transform) {
-        /* For source images, adjust the transform to account
-         * for the drawable offset within the pixman image,
-         * then set the offset to 0 as it will be used
-         * to compute positions within the transformed image.
-         */
-        if (!has_clip) {
-            struct pixman_transform adjusted;
-
-            adjusted = *pict->transform;
-            pixman_transform_translate(&adjusted,
-                                       NULL,
-                                       pixman_int_to_fixed(*xoff),
-                                       pixman_int_to_fixed(*yoff));
-            pixman_image_set_transform(image, &adjusted);
-            *xoff = 0;
-            *yoff = 0;
-        }
-        else
             pixman_image_set_transform(image, pict->transform);
     }
 
@@ -399,10 +224,8 @@ set_image_properties(pixman_image_t * im
      * as the alpha map for this operation
      */
     if (pict->alphaMap && !is_alpha_map) {
-        int alpha_xoff, alpha_yoff;
         pixman_image_t *alpha_map =
-            image_from_pict_internal(pict->alphaMap, FALSE, &alpha_xoff,
-                                     &alpha_yoff, TRUE);
+            image_from_pict_internal(pict->alphaMap, TRUE, TRUE);
 
         pixman_image_set_alpha_map(image, alpha_map, pict->alphaOrigin.x,
                                    pict->alphaOrigin.y);
@@ -436,8 +259,7 @@ set_image_properties(pixman_image_t * im
 }
 
 static pixman_image_t *
-image_from_pict_internal(PicturePtr pict, Bool has_clip, int *xoff, int *yoff,
-                         Bool is_alpha_map)
+image_from_pict_internal(PicturePtr pict, Bool has_clip, Bool is_alpha_map)
 {
     pixman_image_t *image = NULL;
 
@@ -445,7 +267,7 @@ image_from_pict_internal(PicturePtr pict
         return NULL;
 
     if (pict->pDrawable) {
-        image = create_bits_picture(pict, has_clip, xoff, yoff);
+        image = create_bits_picture(pict, has_clip);
     }
     else if (pict->pSourcePict) {
         SourcePict *sp = pict->pSourcePict;
@@ -463,19 +285,17 @@ image_from_pict_internal(PicturePtr pict
             else if (sp->type == SourcePictTypeConical)
                 image = create_conical_gradient_image(gradient);
         }
-        *xoff = *yoff = 0;
     }
 
     if (image)
-        set_image_properties(image, pict, has_clip, xoff, yoff, is_alpha_map);
-
+        set_image_properties (image, pict, is_alpha_map);
     return image;
 }
 
 pixman_image_t *
-image_from_pict(PicturePtr pict, Bool has_clip, int *xoff, int *yoff)
+image_from_pict (PicturePtr pict, Bool has_clip)
 {
-    return image_from_pict_internal(pict, has_clip, xoff, yoff, FALSE);
+    return image_from_pict_internal (pict, has_clip, FALSE);
 }
 
 void
@@ -495,14 +315,11 @@ fbPictureInit(ScreenPtr pScreen, PictFor
         return FALSE;
     ps = GetPictureScreen(pScreen);
     ps->Composite = fbComposite;
-    ps->Glyphs = fbGlyphs;
-    ps->UnrealizeGlyph = fbUnrealizeGlyph;
+    ps->Glyphs = miGlyphs;
     ps->CompositeRects = miCompositeRects;
     ps->RasterizeTrapezoid = fbRasterizeTrapezoid;
-    ps->Trapezoids = fbTrapezoids;
     ps->AddTraps = fbAddTraps;
     ps->AddTriangles = fbAddTriangles;
-    ps->Triangles = fbTriangles;
 
     return TRUE;
 }
