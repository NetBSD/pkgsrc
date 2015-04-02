$NetBSD: patch-src_vstruct.h,v 1.1 2015/04/02 22:16:48 tnn Exp $

From d0550de19cacab3e591641ba358a72fbc798b231 Mon Sep 17 00:00:00 2001
From: Dave Airlie <airlied@redhat.com>
Date: Mon, 22 Sep 2014 12:45:02 +1000
Subject: sis: fix build against latest xserver

--- src/vstruct.h.orig	2012-06-06 08:47:03.000000000 +0000
+++ src/vstruct.h
@@ -237,8 +237,10 @@ struct SiS_Private
 	unsigned char			ChipType;
 	unsigned char			ChipRevision;
 #ifdef SIS_XORG_XF86
+#ifndef XSERVER_LIBPCIACCESS
 	PCITAG				PciTag;
 #endif
+#endif
 #ifdef SIS_LINUX_KERNEL
 	void				*ivideo;
 #endif
