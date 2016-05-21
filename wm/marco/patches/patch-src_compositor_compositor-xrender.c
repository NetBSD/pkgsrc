$NetBSD: patch-src_compositor_compositor-xrender.c,v 1.1 2016/05/21 19:23:00 youri Exp $

SunOS needs _XOPEN_SOURCE 600

--- src/compositor/compositor-xrender.c.orig	2016-03-09 14:31:21.000000000 +0000
+++ src/compositor/compositor-xrender.c
@@ -22,7 +22,7 @@
  */
 
 #define _GNU_SOURCE
-#define _XOPEN_SOURCE 500 /* for usleep() */
+#define _XOPEN_SOURCE 600 /* for usleep() */
 
 #include <config.h>
 
