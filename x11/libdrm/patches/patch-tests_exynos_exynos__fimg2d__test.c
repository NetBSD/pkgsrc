$NetBSD: patch-tests_exynos_exynos__fimg2d__test.c,v 1.1 2022/03/13 15:20:01 tnn Exp $

Fix Linuxisms.

--- tests/exynos/exynos_fimg2d_test.c.orig	2022-02-16 10:00:13.000000000 +0000
+++ tests/exynos/exynos_fimg2d_test.c
@@ -31,7 +31,9 @@
 #include <unistd.h>
 
 #include <sys/mman.h>
+#ifdef __linux__
 #include <linux/stddef.h>
+#endif
 
 #include <xf86drm.h>
 #include <xf86drmMode.h>
