$NetBSD: patch-src_gamma-drm.c,v 1.1 2016/05/18 22:18:43 snj Exp $

No alloca.h on non-Linux/non-SunOS systems.

--- src/gamma-drm.c.orig	2015-05-20 00:07:57.000000000 -0700
+++ src/gamma-drm.c	2015-05-20 00:08:01.000000000 -0700
@@ -21,7 +21,9 @@
 #include <stdlib.h>
 #include <stdint.h>
 #include <string.h>
+#if defined(__linux__) || defined(__sun)
 #include <alloca.h>
+#endif
 #include <sys/types.h>
 #include <sys/stat.h>
 #include <fcntl.h>
