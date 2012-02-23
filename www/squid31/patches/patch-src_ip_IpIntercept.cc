$NetBSD: patch-src_ip_IpIntercept.cc,v 1.1 2012/02/23 05:26:52 taca Exp $

Avoid conflict with IP Fitler's debug().

--- src/ip/IpIntercept.cc.orig	2012-02-05 11:51:32.000000000 +0000
+++ src/ip/IpIntercept.cc
@@ -36,6 +36,10 @@
 
 #if IPF_TRANSPARENT
 
+#ifdef debug
+#undef debug			// XXX: IP Filter might declare debug().
+#endif
+
 #if HAVE_SYS_IOCTL_H
 #include <sys/ioctl.h>
 #endif
@@ -70,6 +74,10 @@
 #include <netinet/ip_nat.h>
 #endif
 
+// Stolen from src/defines.h
+#define debug(SECTION, LEVEL) \
+        do_debug(SECTION, LEVEL) ? (void) 0 : _db_print
+
 #endif /* IPF_TRANSPARENT required headers */
 
 #if PF_TRANSPARENT
