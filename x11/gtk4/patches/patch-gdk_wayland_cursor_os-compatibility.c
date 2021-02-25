$NetBSD: patch-gdk_wayland_cursor_os-compatibility.c,v 1.1 2021/02/25 09:55:55 ryoon Exp $

* NetBSD has no memfd_create.

--- gdk/wayland/cursor/os-compatibility.c.orig	2021-02-07 23:06:57.457976600 +0000
+++ gdk/wayland/cursor/os-compatibility.c
@@ -32,7 +32,9 @@
 #include <string.h>
 #include <stdlib.h>
 
-#define HAVE_MEMFD_CREATE
+#if !defined(__NetBSD__)
+#  define HAVE_MEMFD_CREATE
+#endif
 #ifdef HAVE_MEMFD_CREATE
 #include <sys/mman.h>
 #endif
