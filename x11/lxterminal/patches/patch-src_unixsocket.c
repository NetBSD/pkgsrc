$NetBSD: patch-src_unixsocket.c,v 1.3 2016/06/06 13:44:25 youri Exp $

string.h for memset, merged upstream.

--- src/unixsocket.c.orig	2015-05-21 08:43:09.000000000 -0700
+++ src/unixsocket.c	2015-05-21 08:43:20.000000000 -0700
@@ -20,6 +20,7 @@
 
 #include <sys/socket.h>
 #include <sys/un.h>
+#include <string.h>
 #include <unistd.h>
 #include <fcntl.h>
 #include <errno.h>
