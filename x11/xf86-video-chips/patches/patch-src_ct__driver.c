$NetBSD: patch-src_ct__driver.c,v 1.1 2015/04/02 22:16:46 tnn Exp $

From 9187d76bd4f8d500fc3403b6d4a7bef55508bf2b Mon Sep 17 00:00:00 2001
From: Adam Jackson <ajax@redhat.com>
Date: Fri, 17 Oct 2014 09:49:26 -0400
Subject: Update for xserver 1.17

Signed-off-by: Adam Jackson <ajax@redhat.com>

From 151a1ec855a9ada44907cb6bef06a71e9080504b Mon Sep 17 00:00:00 2001
From: Adam Jackson <ajax@redhat.com>
Date: Tue, 25 Sep 2012 08:54:34 -0400
Subject: Remove mibstore.h

Signed-off-by: Adam Jackson <ajax@redhat.com>

--- src/ct_driver.c.orig	2015-04-02 18:04:37.000000000 +0000
+++ src/ct_driver.c
@@ -96,9 +96,6 @@
 /* All drivers initialising the SW cursor need this */
 #include "mipointer.h"
 
-/* All drivers implementing backing store need this */
-#include "mibstore.h"
-
 /* All drivers using the mi banking wrapper need this */
 #ifdef HAVE_ISA
 #include "mibank.h"
@@ -2101,13 +2098,7 @@ chipsPreInitHiQV(ScrnInfoPtr pScrn, int 
     pScrn->progClock = TRUE;
     cPtr->ClockType = HiQV_STYLE | TYPE_PROGRAMMABLE;
 
-    if (cPtr->pEnt->device->textClockFreq > 0) {
-	SaveClk->Clock = cPtr->pEnt->device->textClockFreq;
-	xf86DrvMsg(pScrn->scrnIndex, X_CONFIG,
-		   "Using textclock freq: %7.3f.\n",
-		   SaveClk->Clock/1000.0);
-    } else
-	SaveClk->Clock = 0;
+    SaveClk->Clock = 0;
 
     xf86DrvMsg(pScrn->scrnIndex, X_PROBED, "Using programmable clocks\n");
 
@@ -2810,13 +2801,7 @@ chipsPreInitWingine(ScrnInfoPtr pScrn, i
 
     if (cPtr->ClockType & TYPE_PROGRAMMABLE) {
 	pScrn->numClocks = NoClocks;
-	if(cPtr->pEnt->device->textClockFreq > 0) {
-	    SaveClk->Clock = cPtr->pEnt->device->textClockFreq;
-	    xf86DrvMsg(pScrn->scrnIndex, X_CONFIG,
-		       "Using textclock freq: %7.3f.\n",
-		       SaveClk->Clock/1000.0);
-	} else
-	   SaveClk->Clock = CRT_TEXT_CLK_FREQ;
+	SaveClk->Clock = CRT_TEXT_CLK_FREQ;
 	xf86DrvMsg(pScrn->scrnIndex, X_PROBED, "Using programmable clocks\n");
     } else {  /* TYPE_PROGRAMMABLE */
 	SaveClk->Clock = chipsGetHWClock(pScrn);
@@ -3503,14 +3488,8 @@ chipsPreInit655xx(ScrnInfoPtr pScrn, int
 
     if (cPtr->ClockType & TYPE_PROGRAMMABLE) {
 	pScrn->numClocks = NoClocks;
-	if (cPtr->pEnt->device->textClockFreq > 0) {
-	    SaveClk->Clock = cPtr->pEnt->device->textClockFreq;
-	    xf86DrvMsg(pScrn->scrnIndex, X_CONFIG,
-		       "Using textclock freq: %7.3f.\n",
-		       SaveClk->Clock/1000.0);
-	} else
-	   SaveClk->Clock = ((cPtr->PanelType & ChipsLCDProbed) ? 
-				 LCD_TEXT_CLK_FREQ : CRT_TEXT_CLK_FREQ);
+        SaveClk->Clock = ((cPtr->PanelType & ChipsLCDProbed) ? 
+			  LCD_TEXT_CLK_FREQ : CRT_TEXT_CLK_FREQ);
 	xf86DrvMsg(pScrn->scrnIndex, X_PROBED, "Using programmable clocks\n");
     } else {  /* TYPE_PROGRAMMABLE */
 	SaveClk->Clock = chipsGetHWClock(pScrn);
@@ -4145,7 +4124,6 @@ CHIPSScreenInit(SCREEN_INIT_ARGS_DECL)
 	    pBankInfo = NULL;
 	    return FALSE;
 	}
-	miInitializeBackingStore(pScreen);
 	xf86SetBackingStore(pScreen);
 
 	/* Initialise cursor functions */
@@ -4296,7 +4274,6 @@ CHIPSScreenInit(SCREEN_INIT_ARGS_DECL)
 	    }
 	}
 	
-	miInitializeBackingStore(pScreen);
 	xf86SetBackingStore(pScreen);
 #ifdef ENABLE_SILKEN_MOUSE
 	xf86SetSilkenMouse(pScreen);
