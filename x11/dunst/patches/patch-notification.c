$NetBSD: patch-notification.c,v 1.1 2016/08/26 17:16:09 joerg Exp $

--- notification.c.orig	2016-08-26 13:36:35.405971570 +0000
+++ notification.c
@@ -6,6 +6,7 @@
 #include <glib.h>
 #include <errno.h>
 #include <string.h>
+#include <libgen.h>
 #include <stdbool.h>
 #include <unistd.h>
 #include <sys/wait.h>
