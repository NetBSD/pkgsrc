$NetBSD: patch-src_radeon__accelfuncs.c,v 1.1 2013/10/31 00:07:24 wiz Exp $

--- src/radeon_accelfuncs.c.orig	2012-06-25 08:19:41.000000000 +0000
+++ src/radeon_accelfuncs.c
@@ -1332,7 +1332,6 @@ FUNC_NAME(RADEONAccelInit)(ScreenPtr pSc
 #endif
 
 #ifdef RENDER
-    info->RenderAccel = FALSE;
     if (info->RenderAccel && info->xaaReq.minorversion >= 2) {
 
 	a->CPUToScreenAlphaTextureFlags = XAA_RENDER_POWER_OF_2_TILE_ONLY;
