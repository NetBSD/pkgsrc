$NetBSD: patch-src_tga__accel.c,v 1.1 2015/04/02 22:16:48 tnn Exp $

From b7022db0559cd1b6cd3eb6b5abf6896a607b478d Mon Sep 17 00:00:00 2001
From: Adam Jackson <ajax@redhat.com>
Date: Tue, 25 Sep 2012 08:55:00 -0400
Subject: Remove mibstore.h

Signed-off-by: Adam Jackson <ajax@redhat.com>

diff --git a/src/tga_accel.c b/src/tga_accel.c
index 35af1a4..b414df5 100644
--- src/tga_accel.c
+++ src/tga_accel.c
@@ -37,7 +37,6 @@
 #include "xf86cmap.h"
 #include "mipointer.h"
 
-#include "mibstore.h"
 #include "miline.h"
 
 #include "tga_regs.h"
