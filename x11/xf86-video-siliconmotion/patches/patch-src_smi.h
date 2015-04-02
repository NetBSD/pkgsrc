$NetBSD: patch-src_smi.h,v 1.1 2015/04/02 22:16:48 tnn Exp $

From c31d7f853d7469085f96f1e37923c260884c611c Mon Sep 17 00:00:00 2001
From: Adam Jackson <ajax@redhat.com>
Date: Tue, 30 Sep 2014 10:34:07 -0400
Subject: Remove dependency on xf86PciInfo.h

Signed-off-by: Adam Jackson <ajax@redhat.com>

From b0b287209cfba5c64c7584b1a82ed2a2f1eab7e6 Mon Sep 17 00:00:00 2001
From: Adam Jackson <ajax@redhat.com>
Date: Tue, 30 Sep 2014 10:28:48 -0400
Subject: Fix build against xserver 1.17

Signed-off-by: Adam Jackson <ajax@redhat.com>

--- src/smi.h.orig	2015-04-02 19:47:42.000000000 +0000
+++ src/smi.h
@@ -37,7 +37,6 @@ authorization from the XFree86 Project a
 
 #include "xf86.h"
 #include "xf86_OSproc.h"
-#include "xf86PciInfo.h"
 #include "xf86Pci.h"
 #include "xf86Cursor.h"
 #include "vgaHW.h"
@@ -68,6 +67,15 @@ authorization from the XFree86 Project a
 /*			D E F I N I T I O N S				      */
 /******************************************************************************/
 
+#define PCI_VENDOR_SMI		0x126F
+#define PCI_CHIP_SMI910		0x0910
+#define PCI_CHIP_SMI810		0x0810
+#define PCI_CHIP_SMI820		0x0820
+#define PCI_CHIP_SMI710		0x0710
+#define PCI_CHIP_SMI712		0x0712
+#define PCI_CHIP_SMI720		0x0720
+#define PCI_CHIP_SMI731		0x0730
+
 #ifndef SMI_DEBUG
 #define SMI_DEBUG		0
 #endif
@@ -221,7 +229,7 @@ typedef struct
     CARD8 *		DataPortBase;	/* Base of data port */
     int			DataPortSize;	/* Size of data port */
     CARD8 *		IOBase;		/* Base of MMIO VGA ports */
-    IOADDRESS		PIOBase;	/* Base of I/O ports */
+    unsigned int	PIOBase;	/* Base of I/O ports */
     unsigned char *	FBBase;		/* Base of FB */
     CARD32		fbMapOffset;    /* offset for fb mapping */
     CARD32		FBOffset;	/* Current visual FB starting
