$NetBSD: patch-src_r128__probe.c,v 1.1 2015/04/02 22:16:47 tnn Exp $

From d757fe10b9ce9493ef3cf854bc03088366aa7256 Mon Sep 17 00:00:00 2001
From: Connor Behan <connor.behan@gmail.com>
Date: Fri, 22 Nov 2013 22:55:59 -0800
Subject: Drop dependence on xf86PciInfo.h

It is about time we stop using this deprecated file and include pciids
locally.

Signed-off-by: Connor Behan <connor.behan@gmail.com>
Reviewed-by: Alex Deucher <alexander.deucher@amd.com>

diff --git a/src/r128_probe.c b/src/r128_probe.c
index 7f1fbda..12e0c1c 100644
--- src/r128_probe.c.orig	2013-10-02 18:30:05.000000000 +0000
+++ src/r128_probe.c
@@ -43,8 +43,6 @@
 #include "atipcirename.h"
 
 #include "xf86.h"
-#include "xf86PciInfo.h"
-
 
 #if GET_ABI_MAJOR(ABI_VIDEODRV_VERSION) < 6
 #include "xf86Resources.h"
