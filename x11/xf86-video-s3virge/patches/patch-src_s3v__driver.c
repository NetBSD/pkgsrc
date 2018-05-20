$NetBSD: patch-src_s3v__driver.c,v 1.3 2018/05/20 07:32:50 wiz Exp $

Fix build with modular-xorg-server-1.20.

--- src/s3v_driver.c.orig	2015-09-26 16:28:11.000000000 +0000
+++ src/s3v_driver.c
@@ -1203,6 +1203,7 @@ S3VPreInit(ScrnInfoPtr pScrn, int flags)
    vga256InfoRec.directMode = XF86DGADirectPresent;
 #endif
 
+#if 0
     /*
      * xf86ValidateModes will check that the mode HTotal and VTotal values
      * don't exceed the chipset's limit if pScrn->maxHValue and
@@ -1214,6 +1215,7 @@ S3VPreInit(ScrnInfoPtr pScrn, int flags)
 			 	/* true for all ViRGE? */
   pScrn->maxHValue = 2048;
   pScrn->maxVValue = 2048;
+#endif
 
     				/* Lower depths default to config file */
   pScrn->virtualX = pScrn->display->virtualX;
