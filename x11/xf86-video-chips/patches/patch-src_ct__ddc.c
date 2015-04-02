$NetBSD: patch-src_ct__ddc.c,v 1.1 2015/04/02 22:16:46 tnn Exp $

From bb03c06322f875e905dec956e06a99b9674e57aa Mon Sep 17 00:00:00 2001
From: Adam Jackson <ajax@redhat.com>
Date: Wed, 21 May 2014 09:38:35 -0400
Subject: ddc: Use own thunk function instead of vgaHWddc1SetSpeedWeak

I plan to remove the Weak functions from future servers.

Signed-off-by: Adam Jackson <ajax@redhat.com>

diff --git a/src/ct_ddc.c b/src/ct_ddc.c
index 5e2346a..677d840 100644
--- src/ct_ddc.c.orig	2012-06-05 18:08:22.000000000 +0000
+++ src/ct_ddc.c
@@ -33,6 +33,12 @@ chips_ddc1Read(ScrnInfoPtr pScrn)
     return (tmp & ddc_mask);
 }
 
+static void
+chips_ddc1SetSpeed(ScrnInfoPtr pScrn, xf86ddcSpeed speed)
+{
+    vgaHWddc1SetSpeed(pScrn, speed);
+}
+
 void
 chips_ddc1(ScrnInfoPtr pScrn)
 {
@@ -93,7 +99,7 @@ chips_ddc1(ScrnInfoPtr pScrn)
 	xf86DrvMsg(pScrn->scrnIndex, X_PROBED, "DDC1 found\n");	
     else return;
 
-    xf86PrintEDID(xf86DoEDID_DDC1(XF86_SCRN_ARG(pScrn), vgaHWddc1SetSpeedWeak(),
+    xf86PrintEDID(xf86DoEDID_DDC1(XF86_SCRN_ARG(pScrn), chips_ddc1SetSpeed,
 				  chips_ddc1Read));
 
     /* restore */
