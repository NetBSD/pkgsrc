$NetBSD: patch-src_rendition.h,v 1.1 2015/04/02 22:16:47 tnn Exp $

From df5646745bf563bb36a0db1796c318fe64bf8efe Mon Sep 17 00:00:00 2001
From: Adam Jackson <ajax@redhat.com>
Date: Tue, 30 Sep 2014 10:24:18 -0400
Subject: Remove dependency on xf86PciInfo.h

Signed-off-by: Adam Jackson <ajax@redhat.com>

From 30a4b73644ee22904824d4847e44ca69369fad02 Mon Sep 17 00:00:00 2001
From: Adam Jackson <ajax@redhat.com>
Date: Tue, 30 Sep 2014 10:21:58 -0400
Subject: Fix build against xserver 1.17

Also port from pci_device_map_region to pci_device_map_range.  Somewhat
alarming that the previous code was using map_region but unmap_range...

Signed-off-by: Adam Jackson <ajax@redhat.com>

--- src/rendition.h.orig	2015-04-02 19:20:48.000000000 +0000
+++ src/rendition.h
@@ -14,9 +14,6 @@
 /* Everything using inb/outb, etc needs "compiler.h" */
 #include "compiler.h"
 
-/* Drivers for PCI hardware need this */
-#include "xf86PciInfo.h"
-
 /* Drivers that need to access the PCI config space directly need this */
 #include "xf86Pci.h"
 
@@ -28,9 +25,6 @@
 /* All drivers initialising the SW cursor need this */
 #include "mipointer.h"
 
-/* All drivers implementing backing store need this */
-#include "mibstore.h"
-
 /* All drivers using the mi colormap manipulation need this */
 #include "micmap.h"
 
@@ -69,4 +63,8 @@
 
 #include "compat-api.h"
 /* end of __RENDITION_H__ */
+
+#define PCI_CHIP_V1000 0x0001
+#define PCI_CHIP_V2x00 0x2000
+
 #endif
