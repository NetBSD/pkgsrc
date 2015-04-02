$NetBSD: patch-src_r128.h,v 1.1 2015/04/02 22:16:47 tnn Exp $

From 9eb693640136bc8bcbe706d642519b4eb23286d4 Mon Sep 17 00:00:00 2001
From: Connor Behan <connor.behan@gmail.com>
Date: Wed, 27 Nov 2013 18:14:43 -0800
Subject: Only declare PCITAG if we need it

If libpciaccess is available, we do not need to declare the deprecated
PciTag member because it will not be used.

Signed-off-by: Connor Behan <connor.behan@gmail.com>
Reviewed-by: Alex Deucher <alexander.deucher@amd.com>

diff --git a/src/r128.h b/src/r128.h
index 90071b4..ee0b1d4 100644
--- src/r128.h.orig	2013-10-02 18:30:05.000000000 +0000
+++ src/r128.h
@@ -301,7 +301,9 @@ struct r128_2d_state {
 typedef struct {
     EntityInfoPtr     pEnt;
     pciVideoPtr       PciInfo;
+#ifndef XSERVER_LIBPCIACCESS
     PCITAG            PciTag;
+#endif
     int               Chipset;
     Bool              Primary;
 
