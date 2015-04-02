$NetBSD: patch-src_alp__driver.c,v 1.1 2015/04/02 22:16:46 tnn Exp $

From df389885adf71ed3b045c2fde9fd3ba4329e1a58 Mon Sep 17 00:00:00 2001
From: Dave Airlie <airlied@gmail.com>
Date: Sat, 20 Sep 2014 18:51:17 +1000
Subject: cirrus: don't use pciTag

Signed-off-by: Dave Airlie <airlied@redhat.com>

diff --git a/src/alp_driver.c b/src/alp_driver.c
index 36f2039..bd5e52f 100644
--- src/alp_driver.c
+++ src/alp_driver.c
@@ -519,9 +519,11 @@ AlpPreInit(ScrnInfoPtr pScrn, int flags)
 	pCir->Chipset = pCir->pEnt->chipset;
 	/* Find the PCI info for this screen */
 	pCir->PciInfo = xf86GetPciInfoForEntity(pCir->pEnt->index);
+#ifndef XSERVER_LIBPCIACCESS
 	pCir->PciTag = pciTag(PCI_DEV_BUS(pCir->PciInfo),
 			      PCI_DEV_DEV(pCir->PciInfo),
 			      PCI_DEV_FUNC(pCir->PciInfo));
+#endif
 
 #if GET_ABI_MAJOR(ABI_VIDEODRV_VERSION) < 12
     if (!xf86IsPc98())
