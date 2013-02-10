$NetBSD: patch-src_ip_Intercept.cc,v 1.1 2013/02/10 18:16:53 adam Exp $

Avoid conflict with IP Fitler's debug().

--- src/ip/Intercept.cc.orig	2013-02-09 07:30:01.000000000 +0000
+++ src/ip/Intercept.cc
@@ -34,9 +34,14 @@
 #include "comm/Connection.h"
 #include "ip/Intercept.h"
 #include "fde.h"
+#include "../tools.h"
 
 #if IPF_TRANSPARENT
 
+#ifdef debug
+#undef debug			// XXX: IP Filter might declare debug().
+#endif
+
 #if HAVE_SYS_IOCTL_H
 #include <sys/ioctl.h>
 #endif
@@ -74,6 +79,10 @@
 #include <errno.h>
 #endif
 
+// Stolen from src/defines.h
+#define debug(SECTION, LEVEL) \
+        do_debug(SECTION, LEVEL) ? (void) 0 : _db_print
+
 #endif /* IPF_TRANSPARENT required headers */
 
 #if PF_TRANSPARENT
