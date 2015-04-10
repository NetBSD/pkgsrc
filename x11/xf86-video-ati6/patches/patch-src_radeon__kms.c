$NetBSD: patch-src_radeon__kms.c,v 1.1 2015/04/10 16:03:01 tnn Exp $

--- src/radeon_kms.c.orig	2012-06-29 13:45:35.000000000 +0000
+++ src/radeon_kms.c
@@ -1039,7 +1039,9 @@ Bool RADEONScreenInit_KMS(SCREEN_INIT_AR
     /* Backing store setup */
     xf86DrvMsgVerb(pScrn->scrnIndex, X_INFO, RADEON_LOGLEVEL_DEBUG,
 		   "Initializing backing store\n");
+#ifdef PKGSRC_LEGACY_XORG_SERVER
     miInitializeBackingStore(pScreen);
+#endif
     xf86SetBackingStore(pScreen);
 
 
