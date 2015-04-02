$NetBSD: patch-src_r128__driver.c,v 1.1 2015/04/02 22:16:47 tnn Exp $

From 9eb693640136bc8bcbe706d642519b4eb23286d4 Mon Sep 17 00:00:00 2001
From: Connor Behan <connor.behan@gmail.com>
Date: Wed, 27 Nov 2013 18:14:43 -0800
Subject: Only declare PCITAG if we need it

If libpciaccess is available, we do not need to declare the deprecated
PciTag member because it will not be used.

Signed-off-by: Connor Behan <connor.behan@gmail.com>
Reviewed-by: Alex Deucher <alexander.deucher@amd.com>

From d757fe10b9ce9493ef3cf854bc03088366aa7256 Mon Sep 17 00:00:00 2001
From: Connor Behan <connor.behan@gmail.com>
Date: Fri, 22 Nov 2013 22:55:59 -0800
Subject: Drop dependence on xf86PciInfo.h

It is about time we stop using this deprecated file and include pciids
locally.

Signed-off-by: Connor Behan <connor.behan@gmail.com>
Reviewed-by: Alex Deucher <alexander.deucher@amd.com>

diff --git a/src/r128_driver.c b/src/r128_driver.c
index 6acdf2d..04a4537 100644
--- src/r128_driver.c.orig	2013-10-02 18:30:05.000000000 +0000
+++ src/r128_driver.c
@@ -84,7 +84,6 @@
 				/* X and server generic header files */
 #include "xf86.h"
 #include "xf86_OSproc.h"
-#include "xf86PciInfo.h"
 #if GET_ABI_MAJOR(ABI_VIDEODRV_VERSION) < 6
 #include "xf86RAC.h"
 #include "xf86Resources.h"
@@ -1955,9 +1954,6 @@ Bool R128PreInit(ScrnInfoPtr pScrn, int 
     }
 
     info->PciInfo      = xf86GetPciInfoForEntity(info->pEnt->index);
-    info->PciTag       = pciTag(PCI_DEV_BUS(info->PciInfo),
-				PCI_DEV_DEV(info->PciInfo),
-				PCI_DEV_FUNC(info->PciInfo));
 
     xf86DrvMsg(pScrn->scrnIndex, X_INFO,
 	       "PCI bus %d card %d func %d\n",
@@ -1966,6 +1962,9 @@ Bool R128PreInit(ScrnInfoPtr pScrn, int 
 	       PCI_DEV_FUNC(info->PciInfo));
 
 #ifndef XSERVER_LIBPCIACCESS
+    info->PciTag       = pciTag(PCI_DEV_BUS(info->PciInfo),
+				PCI_DEV_DEV(info->PciInfo),
+				PCI_DEV_FUNC(info->PciInfo));
     if (xf86RegisterResources(info->pEnt->index, 0, ResNone)) goto fail;
     if (xf86SetOperatingState(resVga, info->pEnt->index, ResUnusedOpr)) goto fail;
 
