$NetBSD: patch-src_sd-daemon.c,v 1.1 2026/03/23 13:09:13 nia Exp $

Use standard header for fcntl(2). Fixes implicit function declaration
on SunOS.

--- src/sd-daemon.c.orig	2026-03-23 12:18:14.370782640 +0000
+++ src/sd-daemon.c
@@ -37,7 +37,7 @@
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
-#include <sys/fcntl.h>
+#include <fcntl.h>
 #include <sys/socket.h>
 #include <sys/stat.h>
 #include <sys/types.h>
