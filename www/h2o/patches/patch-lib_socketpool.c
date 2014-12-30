$NetBSD: patch-lib_socketpool.c,v 1.1 2014/12/30 12:50:12 wiz Exp $

Add header for IPPROTO_TCP to fix build on NetBSD.
https://github.com/h2o/h2o/pull/83

--- lib/socketpool.c.orig	2014-12-25 20:17:49.000000000 +0000
+++ lib/socketpool.c
@@ -24,6 +24,7 @@
 #include <stdlib.h>
 #include <sys/socket.h>
 #include <sys/types.h>
+#include <netinet/in.h>
 #include "h2o/linklist.h"
 #include "h2o/socketpool.h"
 #include "h2o/string_.h"
