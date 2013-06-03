$NetBSD: patch-src_fbdev.c,v 1.1 2013/06/03 00:48:23 rodent Exp $

Send expected type.

--- src/fbdev.c.orig	2012-07-02 11:46:46.000000000 +0000
+++ src/fbdev.c
@@ -425,7 +425,7 @@ FBDevPreInit(ScrnInfoPtr pScrn, int flag
 	}
 #endif
 	/* open device */
-	if (!fbdevHWInit(pScrn,NULL,xf86FindOptionValue(fPtr->pEnt->device->options,"fbdev")))
+	if (!fbdevHWInit(pScrn,NULL,(char *)xf86FindOptionValue(fPtr->pEnt->device->options,"fbdev")))
 		return FALSE;
 	default_depth = fbdevHWGetDepth(pScrn,&fbbpp);
 	if (!xf86SetDepthBpp(pScrn, default_depth, default_depth, fbbpp,
