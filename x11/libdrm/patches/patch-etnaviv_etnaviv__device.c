$NetBSD: patch-etnaviv_etnaviv__device.c,v 1.1 2022/03/13 15:20:01 tnn Exp $

Fix Linuxisms.

--- etnaviv/etnaviv_device.c.orig	2021-07-02 12:49:05.425771700 +0000
+++ etnaviv/etnaviv_device.c
@@ -25,8 +25,10 @@
  */
 
 #include <stdlib.h>
+#ifdef __linux__
 #include <linux/stddef.h>
 #include <linux/types.h>
+#endif
 #include <errno.h>
 #include <sys/mman.h>
 #include <fcntl.h>
