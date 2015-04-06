$NetBSD: patch-core_logging.c,v 1.1 2015/04/06 02:35:54 rodent Exp $

Fix build for OpenBSD and Bitrig.

--- core/logging.c.orig	2015-03-17 07:34:34.000000000 +0000
+++ core/logging.c
@@ -13,7 +13,7 @@
 #define _FILE_OFFSET_BITS 64
 #endif
 
-#if defined(__NetBSD__) || defined(__FreeBSD__) || defined(__DragonFly__)
+#if defined(__NetBSD__) || defined(__FreeBSD__) || defined(__DragonFly__) || defined(__OpenBSD__) || defined(__Bitrig__)
 #include <sys/sysctl.h>
 #endif
 
