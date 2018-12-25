$NetBSD: patch-libsync.h,v 1.2 2018/12/25 01:13:57 sevan Exp $

Fix public header on SunOS.
If ETIME is not defined, use ETIMEDOUT.

--- libsync.h.orig	2018-10-16 14:49:03.000000000 +0000
+++ libsync.h
@@ -33,8 +33,15 @@
 #include <stdint.h>
 #include <string.h>
 #include <sys/ioctl.h>
+#ifdef __sun
+#include <sys/filio.h>
+#endif
 #include <sys/poll.h>
 #include <unistd.h>
+
+#ifndef ETIME
+#define ETIME ETIMEDOUT
+#endif
 
 #if defined(__cplusplus)
 extern "C" {
