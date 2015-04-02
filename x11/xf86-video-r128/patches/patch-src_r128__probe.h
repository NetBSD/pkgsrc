$NetBSD: patch-src_r128__probe.h,v 1.1 2015/04/02 22:16:47 tnn Exp $

From d757fe10b9ce9493ef3cf854bc03088366aa7256 Mon Sep 17 00:00:00 2001
From: Connor Behan <connor.behan@gmail.com>
Date: Fri, 22 Nov 2013 22:55:59 -0800
Subject: Drop dependence on xf86PciInfo.h

It is about time we stop using this deprecated file and include pciids
locally.

Signed-off-by: Connor Behan <connor.behan@gmail.com>
Reviewed-by: Alex Deucher <alexander.deucher@amd.com>

diff --git a/src/r128_probe.h b/src/r128_probe.h
index 41fc0e4..7b55e71 100644
--- src/r128_probe.h.orig	2013-10-02 18:30:05.000000000 +0000
+++ src/r128_probe.h
@@ -38,6 +38,56 @@
 
 #include "xf86str.h"
 
+/* Chip definitions */
+#define PCI_VENDOR_ATI			0x1002
+#define PCI_CHIP_RAGE128LE		0x4C45
+#define PCI_CHIP_RAGE128LF		0x4C46
+#define PCI_CHIP_RAGE128MF		0x4D46
+#define PCI_CHIP_RAGE128ML		0x4D4C
+#define PCI_CHIP_RAGE128PA		0x5041
+#define PCI_CHIP_RAGE128PB		0x5042
+#define PCI_CHIP_RAGE128PC		0x5043
+#define PCI_CHIP_RAGE128PD		0x5044
+#define PCI_CHIP_RAGE128PE		0x5045
+#define PCI_CHIP_RAGE128PF		0x5046
+#define PCI_CHIP_RAGE128PG		0x5047
+#define PCI_CHIP_RAGE128PH		0x5048
+#define PCI_CHIP_RAGE128PI		0x5049
+#define PCI_CHIP_RAGE128PJ		0x504A
+#define PCI_CHIP_RAGE128PK		0x504B
+#define PCI_CHIP_RAGE128PL		0x504C
+#define PCI_CHIP_RAGE128PM		0x504D
+#define PCI_CHIP_RAGE128PN		0x504E
+#define PCI_CHIP_RAGE128PO		0x504F
+#define PCI_CHIP_RAGE128PP		0x5050
+#define PCI_CHIP_RAGE128PQ		0x5051
+#define PCI_CHIP_RAGE128PR		0x5052
+#define PCI_CHIP_RAGE128PS		0x5053
+#define PCI_CHIP_RAGE128PT		0x5054
+#define PCI_CHIP_RAGE128PU		0x5055
+#define PCI_CHIP_RAGE128PV		0x5056
+#define PCI_CHIP_RAGE128PW		0x5057
+#define PCI_CHIP_RAGE128PX		0x5058
+#define PCI_CHIP_RAGE128RE		0x5245
+#define PCI_CHIP_RAGE128RF		0x5246
+#define PCI_CHIP_RAGE128RG		0x5247
+#define PCI_CHIP_RAGE128RK		0x524B
+#define PCI_CHIP_RAGE128RL		0x524C
+#define PCI_CHIP_RAGE128SE		0x5345
+#define PCI_CHIP_RAGE128SF		0x5346
+#define PCI_CHIP_RAGE128SG		0x5347
+#define PCI_CHIP_RAGE128SH		0x5348
+#define PCI_CHIP_RAGE128SK		0x534B
+#define PCI_CHIP_RAGE128SL		0x534C
+#define PCI_CHIP_RAGE128SM		0x534D
+#define PCI_CHIP_RAGE128SN		0x534E
+#define PCI_CHIP_RAGE128TF		0x5446
+#define PCI_CHIP_RAGE128TL		0x544C
+#define PCI_CHIP_RAGE128TR		0x5452
+#define PCI_CHIP_RAGE128TS		0x5453
+#define PCI_CHIP_RAGE128TT		0x5454
+#define PCI_CHIP_RAGE128TU		0x5455
+
 extern DriverRec R128;
 
 typedef struct
