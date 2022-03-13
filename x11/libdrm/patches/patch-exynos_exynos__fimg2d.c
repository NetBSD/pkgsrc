$NetBSD: patch-exynos_exynos__fimg2d.c,v 1.1 2022/03/13 15:20:01 tnn Exp $

Fix Linuxisms.

--- exynos/exynos_fimg2d.c.orig	2022-02-16 10:00:13.000000000 +0000
+++ exynos/exynos_fimg2d.c
@@ -30,7 +30,9 @@
 #include <assert.h>
 
 #include <sys/mman.h>
+#ifdef __linux__
 #include <linux/stddef.h>
+#endif
 
 #include <xf86drm.h>
 
