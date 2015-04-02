$NetBSD: patch-src_cir.h,v 1.1 2015/04/02 22:16:46 tnn Exp $

From df389885adf71ed3b045c2fde9fd3ba4329e1a58 Mon Sep 17 00:00:00 2001
From: Dave Airlie <airlied@gmail.com>
Date: Sat, 20 Sep 2014 18:51:17 +1000
Subject: cirrus: don't use pciTag

Signed-off-by: Dave Airlie <airlied@redhat.com>

diff --git a/src/cir.h b/src/cir.h
index 0a5d403..84f64b5 100644
--- src/cir.h
+++ src/cir.h
@@ -23,7 +23,9 @@ typedef struct {
 	ScrnInfoPtr		pScrn;
 	CARD32			properties;
 	pciVideoPtr		PciInfo;
+#ifndef XSERVER_LIBPCIACCESS
 	PCITAG			PciTag;
+#endif
 	unsigned long		PIOReg;
     union {
 	struct lgRec		*lg;
