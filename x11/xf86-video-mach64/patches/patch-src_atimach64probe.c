$NetBSD: patch-src_atimach64probe.c,v 1.1 2015/04/02 22:16:47 tnn Exp $

From e538ff6b2108117a7ae6644a844c6ce10fc0f1ee Mon Sep 17 00:00:00 2001
From: Connor Behan <connor.behan@gmail.com>
Date: Wed, 27 Nov 2013 23:53:31 -0800
Subject: Drop dependence on xf86PciInfo.h

It is about time we stop using this deprecated file and include pciids
locally.

Signed-off-by: Connor Behan <connor.behan@gmail.com>
Reviewed-by: Alex Deucher <alexander.deucher@amd.com>

diff --git a/src/atimach64probe.c b/src/atimach64probe.c
index e94c3f2..430af6c 100644
--- src/atimach64probe.c
+++ src/atimach64probe.c
@@ -38,7 +38,42 @@
 #include "atiadjust.h"
 #include "ativalid.h"
 
-#include "xf86PciInfo.h"
+/* Chip definitions */
+#define PCI_VENDOR_ATI			0x1002
+#define PCI_CHIP_MACH64CT		0x4354
+#define PCI_CHIP_MACH64CX		0x4358
+#define PCI_CHIP_MACH64ET		0x4554
+#define PCI_CHIP_MACH64GB		0x4742
+#define PCI_CHIP_MACH64GD		0x4744
+#define PCI_CHIP_MACH64GI		0x4749
+#define PCI_CHIP_MACH64GL		0x474C
+#define PCI_CHIP_MACH64GM		0x474D
+#define PCI_CHIP_MACH64GN		0x474E
+#define PCI_CHIP_MACH64GO		0x474F
+#define PCI_CHIP_MACH64GP		0x4750
+#define PCI_CHIP_MACH64GQ		0x4751
+#define PCI_CHIP_MACH64GR		0x4752
+#define PCI_CHIP_MACH64GS		0x4753
+#define PCI_CHIP_MACH64GT		0x4754
+#define PCI_CHIP_MACH64GU		0x4755
+#define PCI_CHIP_MACH64GV		0x4756
+#define PCI_CHIP_MACH64GW		0x4757
+#define PCI_CHIP_MACH64GX		0x4758
+#define PCI_CHIP_MACH64GY		0x4759
+#define PCI_CHIP_MACH64GZ		0x475A
+#define PCI_CHIP_MACH64LB		0x4C42
+#define PCI_CHIP_MACH64LD		0x4C44
+#define PCI_CHIP_MACH64LG		0x4C47
+#define PCI_CHIP_MACH64LI		0x4C49
+#define PCI_CHIP_MACH64LM		0x4C4D
+#define PCI_CHIP_MACH64LN		0x4C4E
+#define PCI_CHIP_MACH64LP		0x4C50
+#define PCI_CHIP_MACH64LQ		0x4C51
+#define PCI_CHIP_MACH64LR		0x4C52
+#define PCI_CHIP_MACH64LS		0x4C53
+#define PCI_CHIP_MACH64VT		0x5654
+#define PCI_CHIP_MACH64VU		0x5655
+#define PCI_CHIP_MACH64VV		0x5656
 
 #ifndef XSERVER_LIBPCIACCESS
 static Bool Mach64Probe(DriverPtr pDriver, int flags);
