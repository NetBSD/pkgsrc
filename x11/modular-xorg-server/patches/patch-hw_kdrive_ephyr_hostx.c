$NetBSD: patch-hw_kdrive_ephyr_hostx.c,v 1.2 2021/06/08 22:51:11 khorben Exp $

Fix Xephyr visual with -parent option

--- hw/kdrive/ephyr/hostx.c.orig	2021-04-13 14:11:40.000000000 +0000
+++ hw/kdrive/ephyr/hostx.c
@@ -36,7 +36,13 @@
 #include <string.h>             /* for memset */
 #include <errno.h>
 #include <time.h>
+#if defined(HAVE_NBCOMPAT_H)
+#include <nbcompat/config.h>
+#include <nbcompat/cdefs.h>
+#include <nbcompat/err.h>
+#else
 #include <err.h>
+#endif
 
 #include <sys/ipc.h>
 #include <sys/shm.h>
@@ -622,7 +628,7 @@ hostx_init(void)
                               scrpriv->win_height,
                               0,
                               XCB_WINDOW_CLASS_COPY_FROM_PARENT,
-                              HostX.visual->visual_id,
+                              XCB_COPY_FROM_PARENT,
                               attr_mask,
                               attrs);
         }
