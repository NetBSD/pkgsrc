$NetBSD: patch-libsync.h,v 1.5 2024/06/10 08:01:20 jperkin Exp $

Fix public header on SunOS.

--- libsync.h.orig	2024-06-10 07:58:37.832119633 +0000
+++ libsync.h
@@ -33,6 +33,9 @@
 #include <stdint.h>
 #include <string.h>
 #include <sys/ioctl.h>
+#ifdef __sun
+#include <sys/filio.h>
+#endif
 #include <poll.h>
 #include <unistd.h>
 
