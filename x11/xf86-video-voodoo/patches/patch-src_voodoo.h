$NetBSD: patch-src_voodoo.h,v 1.1 2015/07/03 10:31:32 wiz Exp $

commit 9172ae566a0e85313fc80ab62b4455393eefe593
Author: Dave Airlie <airlied@redhat.com>
Date:   Mon Sep 22 10:56:02 2014 +1000

    don't use PCITAG in struct anymore

--- src/voodoo.h.orig	2012-07-17 05:21:17.000000000 +0000
+++ src/voodoo.h
@@ -23,7 +23,9 @@ typedef struct {
   
   Bool		      Voodoo2;		/* Set if Voodoo2 */
   pciVideoPtr	      PciInfo;		/* PCI data */
+#ifndef XSERVER_LIBPCIACCESS
   PCITAG	      PciTag;
+#endif
   CARD32	      PhysBase;
   
   CARD32	      Width;		/* Current width */
