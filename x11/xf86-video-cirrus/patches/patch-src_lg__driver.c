$NetBSD: patch-src_lg__driver.c,v 1.1 2015/04/02 22:16:46 tnn Exp $

From df389885adf71ed3b045c2fde9fd3ba4329e1a58 Mon Sep 17 00:00:00 2001
From: Dave Airlie <airlied@gmail.com>
Date: Sat, 20 Sep 2014 18:51:17 +1000
Subject: cirrus: don't use pciTag

Signed-off-by: Dave Airlie <airlied@redhat.com>

diff --git a/src/lg_driver.c b/src/lg_driver.c
index c20bbd0..589d14e 100644
--- src/lg_driver.c
+++ src/lg_driver.c
@@ -382,9 +382,11 @@ LgPreInit(ScrnInfoPtr pScrn, int flags)
 
 	/* Find the PCI info for this screen */
 	pCir->PciInfo = xf86GetPciInfoForEntity(pCir->pEnt->index);
+#ifndef XSERVER_LIBPCIACCESS
 	pCir->PciTag = pciTag(PCI_DEV_BUS(pCir->PciInfo),
 			      PCI_DEV_DEV(pCir->PciInfo),
 			      PCI_DEV_FUNC(pCir->PciInfo));
+#endif
 
 	if (xf86LoadSubModule(pScrn, "int10")) {
 	    xf86Int10InfoPtr int10InfoPtr;
