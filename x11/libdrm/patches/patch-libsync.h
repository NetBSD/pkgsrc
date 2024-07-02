$NetBSD: patch-libsync.h,v 1.6 2024/07/02 16:24:47 wiz Exp $

Fix public header on SunOS.

https://gitlab.freedesktop.org/mesa/drm/-/merge_requests/384

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
 
