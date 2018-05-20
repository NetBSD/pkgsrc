$NetBSD: patch-src_tseng__driver.c,v 1.2 2018/05/20 07:27:31 wiz Exp $

From d2d5c8437e401181f56804cc68594c4831a0983d Mon Sep 17 00:00:00 2001
From: Adam Jackson <ajax@redhat.com>
Date: Tue, 25 Sep 2012 08:55:02 -0400
Subject: Remove mibstore.h

Signed-off-by: Adam Jackson <ajax@redhat.com>

Other chunks: avoid using removed max.Value fields

diff --git a/src/tseng_driver.c b/src/tseng_driver.c
index ffafb19..0db62e5 100644
--- src/tseng_driver.c.orig	2012-07-17 05:21:17.000000000 +0000
+++ src/tseng_driver.c
@@ -39,9 +39,6 @@
 /* All drivers initialising the SW cursor need this */
 #include "mipointer.h"
 
-/* All drivers implementing backing store need this */
-#include "mibstore.h"
-
 #include "fb.h"
 
 #if GET_ABI_MAJOR(ABI_VIDEODRV_VERSION) < 6
@@ -1040,10 +1037,6 @@ TsengPreInit(ScrnInfoPtr pScrn, int flag
     else
 	pTseng->Bytesperpixel = 1;  /* this is fake for < 8bpp, but simplifies other code */
 
-    /* hardware limits */
-    pScrn->maxHValue = Tseng_HMAX;
-    pScrn->maxVValue = Tseng_VMAX;
-
     /*
      * This must happen after pScrn->display has been set because
      * xf86SetWeight references it.
@@ -1128,16 +1121,15 @@ TsengPreInit(ScrnInfoPtr pScrn, int flag
     
     /*
      * xf86ValidateModes will check that the mode HTotal and VTotal values
-     * don't exceed the chipset's limit if pScrn->maxHValue and
-     * pScrn->maxVValue are set.  Since our TsengValidMode() already takes
+     * don't exceed the chipset's limit.  Since our TsengValidMode() already takes
      * care of this, we don't worry about setting them here.
      */
 
     /* Select valid modes from those available */
     i = xf86ValidateModes(pScrn, pScrn->monitor->Modes,
 	pScrn->display->modes, &pTseng->clockRange,
-	NULL, 32, pScrn->maxHValue, 8*pTseng->Bytesperpixel, /* H limits */
-	0, pScrn->maxVValue,	       /* V limits */
+	NULL, 32, Tseng_HMAX, 8*pTseng->Bytesperpixel, /* H limits */
+	0, Tseng_VMAX,	       /* V limits */
 	pScrn->display->virtualX,
 	pScrn->display->virtualY,
 	pTseng->FbMapSize,
@@ -1453,7 +1445,6 @@ TsengScreenInit(SCREEN_INIT_ARGS_DECL)
 	}
     }
 
-    miInitializeBackingStore(pScreen);
     xf86SetSilkenMouse(pScreen);
     /* Initialise cursor functions */
     miDCInitialize(pScreen, xf86GetPointerScreenFuncs());
