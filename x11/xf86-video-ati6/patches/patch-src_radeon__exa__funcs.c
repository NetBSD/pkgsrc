$NetBSD: patch-src_radeon__exa__funcs.c,v 1.1 2014/10/26 10:20:42 wiz Exp $

--- src/radeon_exa_funcs.c.orig	2012-06-25 08:19:41.000000000 +0000
+++ src/radeon_exa_funcs.c
@@ -814,7 +814,7 @@ Bool FUNC_NAME(RADEONDrawInit)(ScreenPtr
 	    info->accel_state->exa->DownloadFromScreen = RADEONDownloadFromScreenCP;
     }
 # if defined(XF86DRM_MODE)
-    else {
+    else if (info->cs) {
 	info->accel_state->exa->UploadToScreen = &RADEONUploadToScreenCS;
         info->accel_state->exa->DownloadFromScreen = &RADEONDownloadFromScreenCS;
     }
