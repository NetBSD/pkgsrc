$NetBSD: patch-src_neo__driver.c,v 1.1 2015/04/02 22:16:47 tnn Exp $

From 6661bdd4551e4e63e983685464a277845aed3012 Mon Sep 17 00:00:00 2001
From: Dave Airlie <airlied@gmail.com>
Date: Sun, 21 Sep 2014 09:51:37 +1000
Subject: neomagic: fix build against master X server.

Signed-off-by: Dave Airlie <airlied@redhat.com>

From 74a9a343f6e156d24539b81f1224b7410acf0e38 Mon Sep 17 00:00:00 2001
From: Adam Jackson <ajax@redhat.com>
Date: Wed, 21 May 2014 14:07:53 -0400
Subject: Use own thunk functions instead of vgaHW*Weak

I plan to remove the Weak functions from a future server

Signed-off-by: Adam Jackson <ajax@redhat.com>

diff --git a/src/neo_driver.c b/src/neo_driver.c
index 7e60f3e..1b0da34 100644
--- src/neo_driver.c.orig	2013-08-16 18:10:25.000000000 +0000
+++ src/neo_driver.c
@@ -1439,6 +1439,12 @@ NEOShadowInit(ScreenPtr pScreen)
 	return TRUE;
 }
 
+static Bool
+NEOSaveScreen(ScreenPtr pScreen, int mode)
+{
+    return vgaHWSaveScreen(pScreen, mode);
+}
+
 /* Mandatory */
 static Bool
 NEOScreenInit(SCREEN_INIT_ARGS_DECL)
@@ -1712,7 +1718,7 @@ NEOScreenInit(SCREEN_INIT_ARGS_DECL)
 
     NEOInitVideo(pScreen);
 
-    pScreen->SaveScreen = vgaHWSaveScreenWeak();
+    pScreen->SaveScreen = NEOSaveScreen;
 
     /* Setup DPMS mode */
     if (nPtr->NeoChipset != NM2070)
@@ -1988,10 +1994,12 @@ neoMapMem(ScrnInfoPtr pScrn)
             }
 #endif
         } else
+#ifdef VIDMEM_MMIO
             nPtr->NeoMMIOBase =
                 xf86MapVidMem(pScrn->scrnIndex,
                               VIDMEM_MMIO, nPtr->NeoMMIOAddr,
                               0x200000L);
+#endif
         if (nPtr->NeoMMIOBase == NULL)
             return FALSE;
     }
@@ -2018,10 +2026,12 @@ neoMapMem(ScrnInfoPtr pScrn)
     }
 #endif
     else
+#ifdef VIDMEM_FRAMEBUFFER
         nPtr->NeoFbBase =
             xf86MapVidMem(pScrn->scrnIndex, VIDMEM_FRAMEBUFFER,
                           (unsigned long)nPtr->NeoLinearAddr,
                           nPtr->NeoFbMapSize);
+#endif
     if (nPtr->NeoFbBase == NULL)
         return FALSE;
     return TRUE;
@@ -3049,6 +3059,12 @@ neo_ddc1Read(ScrnInfoPtr pScrn)
     return (tmp);
 }
 
+static void
+neo_ddc1SetSpeed(ScrnInfoPtr pScrn, xf86ddcSpeed speed)
+{
+    vgaHWddc1SetSpeed(pScrn, speed);
+}
+
 static xf86MonPtr
 neo_ddc1(ScrnInfoPtr pScrn)
 {
@@ -3063,7 +3079,7 @@ neo_ddc1(ScrnInfoPtr pScrn)
     VGAwCR(0x21,0x00);
     VGAwCR(0x1D,0x01);  /* some Voodoo */ 
     VGAwGR(0xA1,0x2F);
-    ret =  xf86DoEDID_DDC1(XF86_SCRN_ARG(pScrn),vgaHWddc1SetSpeedWeak(),neo_ddc1Read);
+    ret =  xf86DoEDID_DDC1(XF86_SCRN_ARG(pScrn),neo_ddc1SetSpeed,neo_ddc1Read);
     /* undo initialization */
     VGAwCR(0x21,reg1);
     VGAwCR(0x1D,reg2);
