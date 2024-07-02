$NetBSD: patch-omap_omap__drm.c,v 1.3 2024/07/02 15:46:37 tnn Exp $

Only include Linux-specific header on Linux.

--- omap/omap_drm.c.orig	2024-07-02 15:43:49.303040722 +0000
+++ omap/omap_drm.c
@@ -27,7 +27,9 @@
  */
 
 #include <stdlib.h>
+#if defined(__linux__)
 #include <linux/types.h>
+#endif
 #include <errno.h>
 #include <sys/mman.h>
 #include <fcntl.h>
