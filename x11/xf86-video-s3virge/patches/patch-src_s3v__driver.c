$NetBSD: patch-src_s3v__driver.c,v 1.1 2015/04/02 22:16:48 tnn Exp $

From 211e2831dcf13c6e5847f6caf894f559d9104c3d Mon Sep 17 00:00:00 2001
From: Adam Jackson <ajax@redhat.com>
Date: Tue, 30 Sep 2014 10:27:13 -0400
Subject: Remove call to miInitializeBackingStore

Signed-off-by: Adam Jackson <ajax@redhat.com>

From 69b9adea709922e53ba422dd7f00aa4ac90d232e Mon Sep 17 00:00:00 2001
From: Adam Jackson <ajax@redhat.com>
Date: Tue, 30 Sep 2014 10:26:17 -0400
Subject: Fix build against xserver 1.17

Signed-off-by: Adam Jackson <ajax@redhat.com>

From d74238ca2faddb2e1c0b48333664688a5079a856 Mon Sep 17 00:00:00 2001
From: Adam Jackson <ajax@redhat.com>
Date: Wed, 21 May 2014 14:10:11 -0400
Subject: Use own thunk function instead of vgaHW*Weak

I plan to remove the Weak functions from a future server.

Signed-off-by: Adam Jackson <ajax@redhat.com>

--- src/s3v_driver.c.orig	2015-04-02 19:28:57.000000000 +0000
+++ src/s3v_driver.c
@@ -2420,7 +2420,6 @@ S3VScreenInit(SCREEN_INIT_ARGS_DECL)
         return FALSE;
   }
 	
-  miInitializeBackingStore(pScreen);
   xf86SetBackingStore(pScreen);
   xf86SetSilkenMouse(pScreen);
   						/* hardware cursor needs to wrap this layer */
@@ -3515,7 +3514,7 @@ S3VEnableMmio(ScrnInfoPtr pScrn)
 {
   vgaHWPtr hwp;
   S3VPtr ps3v;
-  IOADDRESS vgaCRIndex, vgaCRReg;
+  unsigned int vgaCRIndex, vgaCRReg;
   unsigned char val;
   unsigned int PIOOffset = 0;
 
@@ -3584,7 +3583,7 @@ S3VDisableMmio(ScrnInfoPtr pScrn)
 {
   vgaHWPtr hwp;
   S3VPtr ps3v;
-  IOADDRESS vgaCRIndex, vgaCRReg;
+  unsigned int vgaCRIndex, vgaCRReg;
   
   PVERB5("	S3VDisableMmio\n");
   
@@ -3760,6 +3759,12 @@ S3Vddc1Read(ScrnInfoPtr pScrn)
     return ((unsigned int) (tmp & 0x08));
 }
 
+static void
+S3Vddc1SetSpeed(ScrnInfoPtr pScrn, xf86ddcSpeed speed)
+{
+    vgaHWddc1SetSpeed(pScrn, speed);
+}
+
 static Bool
 S3Vddc1(ScrnInfoPtr pScrn)
 {
@@ -3773,7 +3778,7 @@ S3Vddc1(ScrnInfoPtr pScrn)
     OUTREG(DDC_REG,(tmp | 0x12));
     
     if ((pMon = xf86PrintEDID(
-		xf86DoEDID_DDC1(XF86_SCRN_ARG(pScrn),vgaHWddc1SetSpeedWeak(),
+		xf86DoEDID_DDC1(XF86_SCRN_ARG(pScrn), S3Vddc1SetSpeed,
 	                S3Vddc1Read))) != NULL)
 	success = TRUE;
     xf86SetDDCproperties(pScrn,pMon);
