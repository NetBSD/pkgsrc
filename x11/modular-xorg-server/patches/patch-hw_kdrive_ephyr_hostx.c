$NetBSD: patch-hw_kdrive_ephyr_hostx.c,v 1.3 2021/06/24 18:43:08 tnn Exp $

Fix Xephyr visual with -parent option

--- hw/kdrive/ephyr/hostx.c.orig	2020-03-29 20:21:15.000000000 +0000
+++ hw/kdrive/ephyr/hostx.c
@@ -622,7 +622,7 @@ hostx_init(void)
                               scrpriv->win_height,
                               0,
                               XCB_WINDOW_CLASS_COPY_FROM_PARENT,
-                              HostX.visual->visual_id,
+                              XCB_COPY_FROM_PARENT,
                               attr_mask,
                               attrs);
         }
