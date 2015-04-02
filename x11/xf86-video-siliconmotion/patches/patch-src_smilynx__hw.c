$NetBSD: patch-src_smilynx__hw.c,v 1.1 2015/04/02 22:16:48 tnn Exp $

From 08d459d2b548ce89264f45c7018f1cda9f08d795 Mon Sep 17 00:00:00 2001
From: Adam Jackson <ajax@redhat.com>
Date: Tue, 30 Sep 2014 10:31:52 -0400
Subject: Fix a typo

Signed-off-by: Adam Jackson <ajax@redhat.com>

From 9b563415326e02f0b89f716c29b2fc22f393fb96 Mon Sep 17 00:00:00 2001
From: Adam Jackson <ajax@redhat.com>
Date: Wed, 21 May 2014 14:01:02 -0400
Subject: Use own thunk function instead of vgaHW*Weak

I plan to remove the Weak functions from a future server.

Signed-off-by: Adam Jackson <ajax@redhat.com>

--- src/smilynx_hw.c.orig	2015-04-02 19:47:54.000000000 +0000
+++ src/smilynx_hw.c
@@ -572,6 +572,12 @@ SMILynx_ddc1Read(ScrnInfoPtr pScrn)
     LEAVE(ret);
 }
 
+static void
+SMILynx_ddc1SetSpeed(ScrnInfoPtr pScrn, xf86ddcSpeed speed)
+{
+    vgaHWddc1SetSpeed(pScrn, speed);
+}
+
 xf86MonPtr
 SMILynx_ddc1(ScrnInfoPtr pScrn)
 {
@@ -585,7 +591,7 @@ SMILynx_ddc1(ScrnInfoPtr pScrn)
     VGAOUT8_INDEX(pSmi, VGA_SEQ_INDEX, VGA_SEQ_DATA, 0x72, tmp | 0x20);
 
     pMon = xf86PrintEDID(xf86DoEDID_DDC1(XF86_SCRN_ARG(pScrn),
-					 vgaHWddc1SetSpeedWeak(),
+					 SMILynx_ddc1SetSpeed,
 					 SMILynx_ddc1Read));
     VGAOUT8_INDEX(pSmi, VGA_SEQ_INDEX, VGA_SEQ_DATA, 0x72, tmp);
 
