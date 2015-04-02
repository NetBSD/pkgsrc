$NetBSD: patch-src_smi__i2c.c,v 1.1 2015/04/02 22:16:48 tnn Exp $

From c31d7f853d7469085f96f1e37923c260884c611c Mon Sep 17 00:00:00 2001
From: Adam Jackson <ajax@redhat.com>
Date: Tue, 30 Sep 2014 10:34:07 -0400
Subject: Remove dependency on xf86PciInfo.h

Signed-off-by: Adam Jackson <ajax@redhat.com>

--- src/smi_i2c.c.orig	2015-04-02 19:47:50.000000000 +0000
+++ src/smi_i2c.c
@@ -35,7 +35,6 @@ authorization from the XFree86 Project a
 #include "xf86_OSproc.h"
 #include "compiler.h"
 #include "xf86Pci.h"
-#include "xf86PciInfo.h"
 #include "vgaHW.h"
 
 #include "smi.h"
