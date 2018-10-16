$NetBSD: patch-libsync.h,v 1.1 2018/10/16 15:18:08 jperkin Exp $

Fix public header on SunOS.

--- libsync.h.orig	2018-10-04 14:50:03.000000000 +0000
+++ libsync.h
@@ -33,6 +33,9 @@
 #include <stdint.h>
 #include <string.h>
 #include <sys/ioctl.h>
+#ifdef __sun
+#include <sys/filio.h>
+#endif
 #include <sys/poll.h>
 #include <unistd.h>
 
