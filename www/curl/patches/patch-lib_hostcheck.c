$NetBSD: patch-lib_hostcheck.c,v 1.1 2014/03/31 08:45:21 wiz Exp $

Add missing header for DragonflyBSD.
PR 48691 by David Shao.

--- lib/hostcheck.c.orig	2014-03-25 22:01:37.000000000 +0000
+++ lib/hostcheck.c
@@ -31,6 +31,13 @@
 #include "inet_pton.h"
 
 #include "curl_memory.h"
+
+#ifdef ENABLE_IPV6
+#ifdef HAVE_NETINET_IN_H
+#include <netinet/in.h>
+#endif
+#endif
+
 /* The last #include file should be: */
 #include "memdebug.h"
 
