$NetBSD: patch-src_savage__driver.c,v 1.3 2018/05/20 07:30:09 wiz Exp $

Fix build with modular-xorg-server-1.20

--- src/savage_driver.c.orig	2017-01-17 22:43:40.000000000 +0000
+++ src/savage_driver.c
@@ -2034,8 +2034,10 @@ static Bool SavagePreInit(ScrnInfoPtr pS
     xf86DrvMsg(pScrn->scrnIndex, X_PROBED, "Detected current MCLK value of %1.3f MHz\n",
 	       mclk / 1000.0);
 
+#if 0
     pScrn->maxHValue = 2048 << 3;	/* 11 bits of h_total 8-pixel units */
     pScrn->maxVValue = 2048;		/* 11 bits of v_total */
+#endif
     pScrn->virtualX = pScrn->display->virtualX;
     pScrn->virtualY = pScrn->display->virtualY;
 
