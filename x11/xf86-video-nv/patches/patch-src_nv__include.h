$NetBSD: patch-src_nv__include.h,v 1.1 2015/04/02 22:16:47 tnn Exp $

From 49ee1c26ea982e302169c949ebd0abb9d8ef362c Mon Sep 17 00:00:00 2001
From: Jeremy White <jwhite@codeweavers.com>
Date: Thu, 21 Mar 2013 08:59:06 -0700
Subject: Include xf86Modes.h to use functions from
 hw/xfree86/modes/xf86Modes.c.

Signed-off-by: Jeremy White <jwhite@codeweavers.com>
Reviewed-by: Robert Morell <rmorell@nvidia.com>
Reviewed-by: Aaron Plattner <aplattner@nvidia.com>
Signed-off-by: Aaron Plattner <aplattner@nvidia.com>

From fc78fe98222b0204b8a2872a529763d6fe5048da Mon Sep 17 00:00:00 2001
From: Adam Jackson <ajax@redhat.com>
Date: Tue, 25 Sep 2012 08:54:49 -0400
Subject: Remove mibstore.h

Signed-off-by: Adam Jackson <ajax@redhat.com>

diff --git a/src/nv_include.h b/src/nv_include.h
index f174eef..72c74d5 100644
--- src/nv_include.h.orig	2012-07-17 06:48:19.000000000 +0000
+++ src/nv_include.h
@@ -24,12 +24,10 @@
 /* All drivers initialising the SW cursor need this */
 #include "mipointer.h"
 
-/* All drivers implementing backing store need this */
-#include "mibstore.h"
-
 #include "micmap.h"
 
 #include "xf86DDC.h"
+#include "xf86Modes.h"
 
 #include "vbe.h"
 
