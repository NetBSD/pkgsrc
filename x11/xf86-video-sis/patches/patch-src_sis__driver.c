$NetBSD: patch-src_sis__driver.c,v 1.1 2015/04/02 22:16:48 tnn Exp $

From 0f50f8c3db2b9f1c9d4ecab8ad278e9db6418a92 Mon Sep 17 00:00:00 2001
From: Dave Airlie <airlied@redhat.com>
Date: Wed, 12 Nov 2014 09:27:33 +1000
Subject: sis: force build, who uses this crazy code anyways

From d2597696ba81862d80ec17b978d8370c58572e27 Mon Sep 17 00:00:00 2001
From: Dave Airlie <airlied@redhat.com>
Date: Wed, 12 Nov 2014 08:04:21 +1000
Subject: sis: more build fixes against master X server.

From 49796d6a3274adc0250ee07faa6bc63e41c98740 Mon Sep 17 00:00:00 2001
From: Peter Hutterer <peter.hutterer@who-t.net>
Date: Fri, 22 Nov 2013 08:21:18 +1000
Subject: Fix format-security warnings

From 0a4336efaafac4c34d4287b5df586bbb418f7f76 Mon Sep 17 00:00:00 2001
From: Alan Coopersmith <alan.coopersmith@oracle.com>
Date: Sat, 26 Oct 2013 14:27:17 -0700
Subject: Fix HDisplay/VDisplay typos

From 926d4f655c8491b68a338f50c810f6729686ec9f Mon Sep 17 00:00:00 2001
From: Adam Jackson <ajax@redhat.com>
Date: Tue, 25 Sep 2012 08:54:51 -0400
Subject: Remove mibstore.h

--- src/sis_driver.c.orig	2015-04-02 19:58:04.000000000 +0000
+++ src/sis_driver.c
@@ -57,7 +57,6 @@
 #include "fb.h"
 #include "micmap.h"
 #include "mipointer.h"
-#include "mibstore.h"
 #include "edid.h"
 
 #define SIS_NEED_inSISREG
@@ -94,6 +93,10 @@
 #include "dri.h"
 #endif
 
+#ifndef DEFAULT_DPI
+#define DEFAULT_DPI 96
+#endif
+
 /*
  * LookupWindow was removed with video abi 11.
  */
@@ -426,14 +429,14 @@ SISErrorLog(ScrnInfoPtr pScrn, const cha
     static const char *str = "**************************************************\n";
 
     va_start(ap, format);
-    xf86DrvMsg(pScrn->scrnIndex, X_ERROR, str);
+    xf86DrvMsg(pScrn->scrnIndex, X_ERROR, "%s", str);
     xf86DrvMsg(pScrn->scrnIndex, X_ERROR,
 	"                      ERROR:\n");
     xf86VDrvMsgVerb(pScrn->scrnIndex, X_ERROR, 1, format, ap);
     va_end(ap);
     xf86DrvMsg(pScrn->scrnIndex, X_ERROR,
 	"                  END OF MESSAGE\n");
-    xf86DrvMsg(pScrn->scrnIndex, X_ERROR, str);
+    xf86DrvMsg(pScrn->scrnIndex, X_ERROR, "%s", str);
 }
 
 static void
@@ -1911,14 +1914,14 @@ SiSUpdateXineramaScreenInfo(ScrnInfoPtr 
        if(infochanged && !usenonrect) {
 	  xf86DrvMsg(pScrn1->scrnIndex, X_INFO,
 			"Virtual screen size does not match maximum display modes...\n");
-	  xf86DrvMsg(pScrn1->scrnIndex, X_INFO, rectxine);
+	  xf86DrvMsg(pScrn1->scrnIndex, X_INFO, "%s", rectxine);
 
        }
     } else if(infochanged && usenonrect) {
        usenonrect = FALSE;
        xf86DrvMsg(pScrn1->scrnIndex, X_INFO,
 		"Only clone modes available for this virtual screen size...\n");
-       xf86DrvMsg(pScrn1->scrnIndex, X_INFO, rectxine);
+       xf86DrvMsg(pScrn1->scrnIndex, X_INFO, "%s", rectxine);
     }
 
     if(pSiS->maxCRT1_X1) {		/* Means we have at least one non-clone mode */
@@ -3276,9 +3279,11 @@ SISPreInit(ScrnInfoPtr pScrn, int flags)
     pSiS->PciDevice = PCI_CFG_DEV(pSiS->PciInfo); /*SIS_PCI_DEVICE(pSiS->PciInfo);*/
     pSiS->PciFunc = PCI_CFG_FUNC(pSiS->PciInfo);  /*SIS_PCI_FUNC(pSiS->PciInfo);*/
 
+#ifndef XSERVER_LIBPCIACCESS
     pSiS->PciTag = pciTag(PCI_DEV_BUS(pSiS->PciInfo),
 			  PCI_DEV_DEV(pSiS->PciInfo),
 			  PCI_DEV_FUNC(pSiS->PciInfo));
+#endif
 
 #ifdef SIS_NEED_MAP_IOP
     /********************************************/
@@ -3902,7 +3907,9 @@ SISPreInit(ScrnInfoPtr pScrn, int flags)
        if(pSiSEnt) pSiSEnt->SiS_Pr = pSiS->SiS_Pr;
 #endif
        memset(pSiS->SiS_Pr, 0, sizeof(struct SiS_Private));
+#ifndef XSERVER_LIBPCIACCESS
        pSiS->SiS_Pr->PciTag = pSiS->PciTag;
+#endif
        pSiS->SiS_Pr->ChipType = pSiS->ChipType;
        pSiS->SiS_Pr->ChipRevision = pSiS->ChipRev;
        pSiS->SiS_Pr->SiS_Backup70xx = 0xff;
@@ -7131,7 +7138,9 @@ static Bool
 SISMapMem(ScrnInfoPtr pScrn)
 {
     SISPtr pSiS = SISPTR(pScrn);
+#ifndef XSERVER_LIBPCIACCESS
     int mmioFlags = VIDMEM_MMIO;
+#endif
 #ifdef SISDUALHEAD
     SISEntPtr pSiSEnt = pSiS->entityPrivate;
 #endif
@@ -7141,9 +7150,11 @@ SISMapMem(ScrnInfoPtr pScrn)
      * (For Alpha, we need to map SPARSE memory, since we need
      * byte/short access.)
      */
+#ifndef XSERVER_LIBPCIACCESS
 #if defined(__alpha__)
     mmioFlags |= VIDMEM_SPARSE;
 #endif
+#endif
 
 #ifdef SISDUALHEAD
     if(pSiS->DualHeadMode) {
@@ -7344,7 +7355,11 @@ SISUnmapMem(ScrnInfoPtr pScrn)
         if(pSiSEnt->MapCountIOBase) {
 	    pSiSEnt->MapCountIOBase--;
 	    if((pSiSEnt->MapCountIOBase == 0) || (pSiSEnt->forceUnmapIOBase)) {
+#ifndef XSERVER_LIBPCIACCESS
 		xf86UnMapVidMem(pScrn->scrnIndex, (pointer)pSiSEnt->IOBase, (pSiS->mmioSize * 1024));
+#else
+	        pci_device_unmap_range(pSiS->PciInfo, pSiSEnt->IOBase, (pSiS->mmioSize * 1024));
+#endif
 		pSiSEnt->IOBase = NULL;
 		pSiSEnt->MapCountIOBase = 0;
 		pSiSEnt->forceUnmapIOBase = FALSE;
@@ -7355,7 +7370,11 @@ SISUnmapMem(ScrnInfoPtr pScrn)
 	if(pSiSEnt->MapCountIOBaseDense) {
 	    pSiSEnt->MapCountIOBaseDense--;
 	    if((pSiSEnt->MapCountIOBaseDense == 0) || (pSiSEnt->forceUnmapIOBaseDense)) {
+#ifndef XSERVER_LIBPCIACCESS
 		xf86UnMapVidMem(pScrn->scrnIndex, (pointer)pSiSEnt->IOBaseDense, (pSiS->mmioSize * 1024));
+#else
+		pci_device_unmap_range(pSiS->PciInfo, (pointer)pSiSEnt->IOBaseDense, (pSiS->mmioSize * 1024));
+#endif
 		pSiSEnt->IOBaseDense = NULL;
 		pSiSEnt->MapCountIOBaseDense = 0;
 		pSiSEnt->forceUnmapIOBaseDense = FALSE;
@@ -7366,7 +7385,11 @@ SISUnmapMem(ScrnInfoPtr pScrn)
 	if(pSiSEnt->MapCountFbBase) {
 	    pSiSEnt->MapCountFbBase--;
 	    if((pSiSEnt->MapCountFbBase == 0) || (pSiSEnt->forceUnmapFbBase)) {
+#ifndef XSERVER_LIBPCIACCESS
 		xf86UnMapVidMem(pScrn->scrnIndex, (pointer)pSiSEnt->RealFbBase, pSiS->FbMapSize);
+#else
+		pci_device_unmap_range(pSiS->PciInfo, (pointer)pSiSEnt->RealFbBase, pSiS->FbMapSize);
+#endif
 		pSiSEnt->FbBase = pSiSEnt->RealFbBase = NULL;
 		pSiSEnt->MapCountFbBase = 0;
 		pSiSEnt->forceUnmapFbBase = FALSE;
@@ -7376,13 +7399,25 @@ SISUnmapMem(ScrnInfoPtr pScrn)
 	}
     } else {
 #endif
+#ifndef XSERVER_LIBPCIACCESS
 	xf86UnMapVidMem(pScrn->scrnIndex, (pointer)pSiS->IOBase, (pSiS->mmioSize * 1024));
+#else
+	pci_device_unmap_range(pSiS->PciInfo, (pointer)pSiS->IOBase, (pSiS->mmioSize * 1024));
+#endif
 	pSiS->IOBase = NULL;
 #ifdef __alpha__
+#ifndef XSERVER_LIBPCIACCESS
 	xf86UnMapVidMem(pScrn->scrnIndex, (pointer)pSiS->IOBaseDense, (pSiS->mmioSize * 1024));
+#else
+	pci_device_unmap_range(pSiS->PciInfo, (pointer)pSiS->IOBaseDense, (pSiS->mmioSize * 1024));
+#endif
 	pSiS->IOBaseDense = NULL;
 #endif
+#ifndef XSERVER_LIBPCIACCESS
 	xf86UnMapVidMem(pScrn->scrnIndex, (pointer)pSiS->RealFbBase, pSiS->FbMapSize);
+#else
+	pci_device_unmap_range(pSiS->PciInfo, (pointer)pSiS->RealFbBase, pSiS->FbMapSize);
+#endif
 	pSiS->FbBase = pSiS->RealFbBase = NULL;
 #ifdef SISDUALHEAD
     }
@@ -8859,7 +8894,6 @@ SISScreenInit(SCREEN_INIT_ARGS_DECL)
     }
     pSiS->SiSFastVidCopyDone = TRUE;
 
-    miInitializeBackingStore(pScreen);
     xf86SetBackingStore(pScreen);
     xf86SetSilkenMouse(pScreen);
 
@@ -9351,6 +9385,7 @@ SISMergedPointerMoved(SCRN_ARG_TYPE arg,
 	}
      }
      if(doit) {
+#if GET_ABI_MAJOR(ABI_XINPUT_VERSION) < 20 /* screw it */
 	sigstate = xf86BlockSIGIO();
 #if GET_ABI_MAJOR(ABI_XINPUT_VERSION) >= 15
         {
@@ -9368,6 +9403,7 @@ SISMergedPointerMoved(SCRN_ARG_TYPE arg,
 	miPointerAbsoluteCursor(x, y, currentTime.milliseconds);
 #endif
 	xf86UnblockSIGIO(sigstate);
+#endif
 	return;
      }
   }
@@ -13725,12 +13761,12 @@ SiS_CheckModeCRT2(ScrnInfoPtr pScrn, Dis
       if( ((mode->HDisplay <= pSiS->LCDwidth) &&
            (mode->VDisplay <= pSiS->LCDheight)) ||
 	  ((pSiS->SiS_Pr->SiS_CustomT == CUT_PANEL848) &&
-	   (((mode->HDisplay == 1360) && (mode->HDisplay == 768)) ||
-	    ((mode->HDisplay == 1024) && (mode->HDisplay == 768)) ||
-	    ((mode->HDisplay ==  800) && (mode->HDisplay == 600)))) ||
+	   (((mode->HDisplay == 1360) && (mode->VDisplay == 768)) ||
+	    ((mode->HDisplay == 1024) && (mode->VDisplay == 768)) ||
+	    ((mode->HDisplay ==  800) && (mode->VDisplay == 600)))) ||
 	  ((pSiS->SiS_Pr->SiS_CustomT == CUT_PANEL856) &&
-	   (((mode->HDisplay == 1024) && (mode->HDisplay == 768)) ||
-	    ((mode->HDisplay ==  800) && (mode->HDisplay == 600)))) ) {
+	   (((mode->HDisplay == 1024) && (mode->VDisplay == 768)) ||
+	    ((mode->HDisplay ==  800) && (mode->VDisplay == 600)))) ) {
 
 	 ModeIndex = SiS_GetModeID_LCD(pSiS->VGAEngine, VBFlags, mode->HDisplay, mode->VDisplay, i,
 				pSiS->FSTN, pSiS->SiS_Pr->SiS_CustomT, pSiS->LCDwidth, pSiS->LCDheight,
@@ -13991,6 +14027,7 @@ SiS_GetSetBIOSScratch(ScrnInfoPtr pScrn,
        break;
     }
 
+#ifndef XSERVER_LIBPCIACCESS
 #ifdef SIS_USE_BIOS_SCRATCH
     if(SISPTR(pScrn)->Primary) {
        base = xf86MapVidMem(pScrn->scrnIndex, VIDMEM_MMIO, 0, 0x2000);
@@ -14009,6 +14046,7 @@ SiS_GetSetBIOSScratch(ScrnInfoPtr pScrn,
        xf86UnMapVidMem(pScrn->scrnIndex, base, 0x2000);
     }
 #endif
+#endif
     return ret;
 }
 
