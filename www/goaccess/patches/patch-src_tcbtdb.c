$NetBSD: patch-src_tcbtdb.c,v 1.1 2020/03/23 17:15:57 roy Exp $

va_list requires stdarg.h

--- src/tcbtdb.c.orig	2020-03-23 16:42:43.613997461 +0000
+++ src/tcbtdb.c	2020-03-23 16:43:08.793204575 +0000
@@ -37,6 +37,7 @@
 #include <tcutil.h>
 #include <fcntl.h>
 #include <sys/types.h>
+#include <stdarg.h>
 #include <unistd.h>
 
 #include "tcbtdb.h"
