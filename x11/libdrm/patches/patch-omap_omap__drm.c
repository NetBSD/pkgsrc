$NetBSD: patch-omap_omap__drm.c,v 1.4 2024/07/02 16:24:47 wiz Exp $

Only include Linux-specific header on Linux.

https://gitlab.freedesktop.org/mesa/drm/-/merge_requests/384

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
