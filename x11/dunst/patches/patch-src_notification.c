$NetBSD: patch-src_notification.c,v 1.1 2017/07/20 10:39:25 leot Exp $

<libgen.h> is needed for basename(3).

--- src/notification.c.orig	2017-07-12 08:22:04.000000000 +0000
+++ src/notification.c
@@ -6,6 +6,7 @@
 #include <assert.h>
 #include <errno.h>
 #include <glib.h>
+#include <libgen.h>
 #include <stdbool.h>
 #include <stdio.h>
 #include <stdlib.h>
