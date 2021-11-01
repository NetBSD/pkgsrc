$NetBSD: patch-libi3_create__socket.c,v 1.1 2021/11/01 20:42:58 wiz Exp $

Include header for S_IRWXU.

--- libi3/create_socket.c.orig	2021-10-19 06:37:59.902370500 +0000
+++ libi3/create_socket.c
@@ -14,6 +14,7 @@
 #include <stdlib.h>
 #include <string.h>
 #include <sys/socket.h>
+#include <sys/stat.h>
 #include <sys/un.h>
 
 /*
