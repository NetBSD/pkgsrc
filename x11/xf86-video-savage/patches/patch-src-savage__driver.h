$NetBSD: patch-src-savage__driver.h,v 1.1 2015/04/02 22:16:48 tnn Exp $

From 2e9217bb88b76cebfcd2b65b76c8733f80da77ea Mon Sep 17 00:00:00 2001
From: Jeremy White <jwhite@codeweavers.com>
Date: Thu, 21 Mar 2013 10:59:13 -0500
Subject: Include xf86Modes.h to use functions from
 hw/xfree86/modes/xf86Modes.c.

Signed-off-by: Jeremy White <jwhite@codeweavers.com>
Reviewed-by: Robert Morell <rmorell@nvidia.com>

diff --git a/src/savage_driver.h b/src/savage_driver.h
index ec4b1ea..de042af 100644
--- src/savage_driver.h
+++ src/savage_driver.h
@@ -54,6 +54,7 @@
 #if GET_ABI_MAJOR(ABI_VIDEODRV_VERSION) < 6
 #include "xf86Resources.h"
 #endif
+#include "xf86Modes.h"
 #include "xf86Pci.h"
 #include "xf86_OSproc.h"
 #include "xf86Cursor.h"
