$NetBSD: patch-omap_omap__drm.c,v 1.1 2022/03/13 15:20:01 tnn Exp $

Fix Linuxisms.

--- omap/omap_drm.c.orig	2022-02-16 10:00:13.000000000 +0000
+++ omap/omap_drm.c
@@ -27,8 +27,10 @@
  */
 
 #include <stdlib.h>
+#ifdef __linux__
 #include <linux/stddef.h>
 #include <linux/types.h>
+#endif
 #include <errno.h>
 #include <sys/mman.h>
 #include <fcntl.h>
