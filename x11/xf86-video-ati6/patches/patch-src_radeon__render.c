$NetBSD: patch-src_radeon__render.c,v 1.1 2013/10/31 00:07:24 wiz Exp $

--- src/radeon_render.c.orig	2012-06-25 08:19:41.000000000 +0000
+++ src/radeon_render.c
@@ -409,6 +409,9 @@ static Bool FUNC_NAME(R100SetupTexture)(
     dst_pitch = RADEON_ALIGN(width * tex_bytepp, 64);
     size = dst_pitch * height;
 
+    info->accel_state->texW[0] = width;
+    info->accel_state->texH[0] = height;
+
     if ((flags & XAA_RENDER_REPEAT) && (height != 1) &&
 	(RADEON_ALIGN(width * tex_bytepp, 32) != dst_pitch))
 	return FALSE;
@@ -432,7 +435,7 @@ static Bool FUNC_NAME(R100SetupTexture)(
 	txformat |= ATILog2(width) << RADEON_TXFORMAT_WIDTH_SHIFT;
 	txformat |= ATILog2(height) << RADEON_TXFORMAT_HEIGHT_SHIFT;
     } else {
-	tex_size = (height << 16) | width;
+	tex_size = ((height - 1) << 16) | (width - 1);
 	txformat |= RADEON_TXFORMAT_NON_POWER2;
     }
 
@@ -462,7 +465,6 @@ static Bool FUNC_NAME(R100SetupTexture)(
 
     if (info->accel_state->accel->NeedToSync)
 	info->accel_state->accel->Sync(pScrn);
-
     while (height--) {
 	memcpy(dst, src, width * tex_bytepp);
 	src += src_pitch;
@@ -633,10 +635,10 @@ FUNC_NAME(R100SubsequentCPUToScreenTextu
 
     r = width + l;
     b = height + t;
-    fl = srcx;
-    fr = srcx + width;
-    ft = srcy;
-    fb = srcy + height;
+    fl = (float)srcx / info->accel_state->texW[0];
+    fr = (float)(srcx + width) / info->accel_state->texW[0];
+    ft = (float)srcy / info->accel_state->texH[0];
+    fb = (float)(srcy + height) / info->accel_state->texH[0];
 
 #ifdef ACCEL_CP
     BEGIN_RING(25);
