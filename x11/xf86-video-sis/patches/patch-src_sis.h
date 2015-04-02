$NetBSD: patch-src_sis.h,v 1.1 2015/04/02 22:16:48 tnn Exp $

From d0550de19cacab3e591641ba358a72fbc798b231 Mon Sep 17 00:00:00 2001
From: Dave Airlie <airlied@redhat.com>
Date: Mon, 22 Sep 2014 12:45:02 +1000
Subject: sis: fix build against latest xserver

From 7d4402786b758de3e6ce2641e15a39d612d5c518 Mon Sep 17 00:00:00 2001
From: Adam Jackson <ajax@redhat.com>
Date: Mon, 15 Oct 2012 19:11:30 -0400
Subject: Stop including xf86Priv.h

As the name might suggest, it's server-private.

--- src/sis.h.orig	2015-04-02 19:58:00.000000000 +0000
+++ src/sis.h
@@ -75,7 +75,6 @@
 
 #include "compiler.h"
 #include "xf86Pci.h"
-#include "xf86Priv.h"
 #include "xf86_OSproc.h"
 #if GET_ABI_MAJOR(ABI_VIDEODRV_VERSION) < 6
 #include "xf86Resources.h"
@@ -1005,7 +1004,9 @@ typedef struct {
     ScrnInfoPtr		pScrn;
     pciVideoPtr		PciInfo;
     int			PciBus, PciDevice, PciFunc;
+#ifndef XSERVER_LIBPCIACCESS
     PCITAG		PciTag;
+#endif
     EntityInfoPtr	pEnt;
     int			Chipset;
     unsigned char	ChipType;
