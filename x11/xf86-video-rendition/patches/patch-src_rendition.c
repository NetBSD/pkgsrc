$NetBSD: patch-src_rendition.c,v 1.1 2015/04/02 22:16:47 tnn Exp $

From 30a4b73644ee22904824d4847e44ca69369fad02 Mon Sep 17 00:00:00 2001
From: Adam Jackson <ajax@redhat.com>
Date: Tue, 30 Sep 2014 10:21:58 -0400
Subject: Fix build against xserver 1.17

Also port from pci_device_map_region to pci_device_map_range.  Somewhat
alarming that the previous code was using map_region but unmap_range...

Signed-off-by: Adam Jackson <ajax@redhat.com>

From 3a3ee1c45e54a808947cc26ca11f0a5299571053 Mon Sep 17 00:00:00 2001
From: Adam Jackson <ajax@redhat.com>
Date: Tue, 25 Sep 2012 08:54:50 -0400
Subject: Remove mibstore.h

Signed-off-by: Adam Jackson <ajax@redhat.com>

--- src/rendition.c.orig	2015-04-02 19:20:42.000000000 +0000
+++ src/rendition.c
@@ -1173,7 +1173,6 @@ renditionScreenInit(SCREEN_INIT_ARGS_DEC
     fbPictureInit (pScreen, 0, 0);
 
     xf86SetBlackWhitePixels(pScreen);
-    miInitializeBackingStore(pScreen);
    
     /*********************************************************/
     /* The actual setup of the driver-specific code          */
@@ -1372,6 +1371,18 @@ renditionMapMem(ScrnInfoPtr pScreenInfo)
        /* Override on users request */
     WriteCombine
 	= xf86ReturnOptValBool(pRendition->Options, OPTION_FBWC, WriteCombine);
+#ifdef XSERVER_LIBPCIACCESS
+    mapOption = PCI_DEV_MAP_FLAG_WRITABLE;
+    if (WriteCombine)
+	mapOption |= PCI_DEV_MAP_FLAG_WRITE_COMBINE;
+
+    err = pci_device_map_range(pRendition->PciInfo,
+			       pRendition->PciInfo->regions[0].base_addr,
+			       pRendition->PciInfo->regions[0].size,
+			       mapOption, (void *)&pRendition->board.vmem_base);
+
+    return (err == 0);
+#else
     if (WriteCombine) {
 	xf86DrvMsg(pScreenInfo->scrnIndex, X_CONFIG,
 		   ("Requesting Write-Combined memory access\n"));
@@ -1382,12 +1393,6 @@ renditionMapMem(ScrnInfoPtr pScreenInfo)
 	mapOption = VIDMEM_MMIO;
     }
 
-#ifdef XSERVER_LIBPCIACCESS
-    err = pci_device_map_region(pRendition->PciInfo, 0, TRUE);
-    pRendition->board.vmem_base = pRendition->PciInfo->regions[0].memory;
-
-    return (err == 0);
-#else
     pRendition->board.vmem_base=
         xf86MapPciMem(pScreenInfo->scrnIndex, mapOption,
 		      pRendition->pcitag,
@@ -1416,7 +1421,7 @@ renditionUnmapMem(ScrnInfoPtr pScreenInf
 #else
     pci_device_unmap_range(pRendition->PciInfo, 
 			   pRendition->board.vmem_base,
-			   pScreenInfo->videoRam * 1024);
+			   pRendition->PciInfo->regions[0].size);
 #endif
     return TRUE;
 #ifdef DEBUG0
