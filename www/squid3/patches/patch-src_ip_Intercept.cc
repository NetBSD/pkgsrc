$NetBSD: patch-src_ip_Intercept.cc,v 1.2 2013/04/27 17:51:24 tron Exp $

Avoid conflict with IP Fitler's debug().

--- src/ip/Intercept.cc.orig	2013-04-27 04:34:48.000000000 +0100
+++ src/ip/Intercept.cc	2013-04-27 18:40:24.000000000 +0100
@@ -38,6 +38,10 @@
 
 #if IPF_TRANSPARENT
 
+#ifdef debug
+#undef debug			// XXX: IP Filter might declare debug().
+#endif
+
 #if HAVE_SYS_IOCTL_H
 #include <sys/ioctl.h>
 #endif
@@ -75,6 +79,10 @@
 #include <errno.h>
 #endif
 
+// Stolen from src/defines.h
+#define debug(SECTION, LEVEL) \
+        do_debug(SECTION, LEVEL) ? (void) 0 : _db_print
+
 #endif /* IPF_TRANSPARENT required headers */
 
 #if PF_TRANSPARENT
