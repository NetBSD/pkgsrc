$NetBSD: patch-libgnome-desktop_libgsystem_gsystem-file-utils.c,v 1.1.2.2 2014/08/22 15:25:10 tron Exp $

Add fcntl.h for openat().

--- libgnome-desktop/libgsystem/gsystem-file-utils.c.orig	2013-10-04 22:18:43.000000000 +0000
+++ libgnome-desktop/libgsystem/gsystem-file-utils.c
@@ -37,6 +37,8 @@
 #include <glib-unix.h>
 #include <limits.h>
 #include <dirent.h>
+/* for openat() */
+#include <fcntl.h>
 
 static int
 close_nointr (int fd)
