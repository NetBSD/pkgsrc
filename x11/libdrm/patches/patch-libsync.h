$NetBSD: patch-libsync.h,v 1.3 2019/01/22 21:50:47 wiz Exp $

Fix public header on SunOS.
If ETIME is not defined, use ETIMEDOUT.

--- libsync.h.orig	2019-01-22 16:32:41.000000000 +0000
+++ libsync.h
@@ -33,9 +33,16 @@
 #include <stdint.h>
 #include <string.h>
 #include <sys/ioctl.h>
+#ifdef __sun
+#include <sys/filio.h>
+#endif
 #include <sys/poll.h>
 #include <unistd.h>
 
+#ifndef ETIME
+#define ETIME ETIMEDOUT
+#endif
+
 #if defined(__cplusplus)
 extern "C" {
 #endif
