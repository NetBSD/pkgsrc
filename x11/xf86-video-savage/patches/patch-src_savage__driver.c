$NetBSD: patch-src_savage__driver.c,v 1.1 2015/04/02 22:16:48 tnn Exp $

From 16a672d1ba183601d513c4cdca32b47e926a6d1e Mon Sep 17 00:00:00 2001
From: Adam Jackson <ajax@redhat.com>
Date: Wed, 21 May 2014 14:11:46 -0400
Subject: Use own thunk function instead of vgaHW*Weak

I plan to remove the Weak functions from a future server.

Signed-off-by: Adam Jackson <ajax@redhat.com>

diff --git a/src/savage_driver.c b/src/savage_driver.c
index bca2c60..e82794f 100644
--- src/savage_driver.c
+++ src/savage_driver.c
@@ -4576,6 +4576,12 @@ SavageDDC1Read(ScrnInfoPtr pScrn)
     return ((unsigned int) (tmp & 0x08));
 }
 
+static void
+SavageDDC1SetSpeed(ScrnInfoPtr pScrn, xf86ddcSpeed speed)
+{
+    vgaHWddc1SetSpeed(pScrn, speed);
+}
+
 static Bool
 SavageDDC1(ScrnInfoPtr pScrn)
 {
@@ -4589,7 +4595,8 @@ SavageDDC1(ScrnInfoPtr pScrn)
     InI2CREG(byte,psav->I2CPort);
     OutI2CREG(byte | 0x12,psav->I2CPort);
 
-    pMon = xf86DoEDID_DDC1(XF86_SCRN_ARG(pScrn),vgaHWddc1SetSpeedWeak(),SavageDDC1Read);
+    pMon = xf86DoEDID_DDC1(XF86_SCRN_ARG(pScrn), SavageDDC1SetSpeed,
+			   SavageDDC1Read);
     if (!pMon)
         return FALSE;
     
