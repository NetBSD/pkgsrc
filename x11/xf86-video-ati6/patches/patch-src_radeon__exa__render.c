$NetBSD: patch-src_radeon__exa__render.c,v 1.2 2013/10/31 00:42:51 wiz Exp $

macallan; Tue Oct 29 01:06:03 UTC 2013:
Don't endian-twiddle solid source colours in composite operations on R1xx
Now gtk2-rendered text looks right again with EXA and xrender acceleration
enabled.
Probably needs similar fixes for R2xx, also needs testing on little-endian
hardware.

--- src/radeon_exa_render.c.orig	2012-06-25 08:19:41.000000000 +0000
+++ src/radeon_exa_render.c
@@ -649,7 +649,7 @@ static Bool FUNC_NAME(R100PrepareComposi
     CHECK_OFFSET(pDst, 0x0f, "destination");
 
     if (!pSrc) {
-	pSrc = RADEONSolidPixmap(pScreen, cpu_to_le32(pSrcPicture->pSourcePict->solidFill.color));
+	pSrc = RADEONSolidPixmap(pScreen, pSrcPicture->pSourcePict->solidFill.color);
 	if (!pSrc)
 	    RADEON_FALLBACK("Failed to create solid scratch pixmap\n");
     }
@@ -661,7 +661,7 @@ static Bool FUNC_NAME(R100PrepareComposi
 	return FALSE;
 
     if (pMaskPicture && !pMask) {
-	pMask = RADEONSolidPixmap(pScreen, cpu_to_le32(pMaskPicture->pSourcePict->solidFill.color));
+	pMask = RADEONSolidPixmap(pScreen, pMaskPicture->pSourcePict->solidFill.color);
 	if (!pMask) {
 	    if (!pSrcPicture->pDrawable)
 		pScreen->DestroyPixmap(pSrc);
