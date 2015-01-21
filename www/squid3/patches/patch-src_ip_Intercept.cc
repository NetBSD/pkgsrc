$NetBSD: patch-src_ip_Intercept.cc,v 1.4 2015/01/21 11:23:16 adam Exp $

Avoid conflict with IP Fitler's debug().

--- src/ip/Intercept.cc.orig	2015-01-13 12:52:01.000000000 +0000
+++ src/ip/Intercept.cc
@@ -21,6 +21,10 @@
 
 #if IPF_TRANSPARENT
 
+#ifdef debug
+#undef debug		// XXX: IP Filter might declare debug().
+#endif
+
 #if !defined(IPFILTER_VERSION)
 #define IPFILTER_VERSION        5000004
 #endif
@@ -68,6 +72,10 @@
 #include <netinet/ip_nat.h>
 #endif
 
+// Stolen from src/defines.h
+#define debug(SECTION, LEVEL) \
+        do_debug(SECTION, LEVEL) ? (void) 0 : _db_print
+
 #endif /* IPF_TRANSPARENT required headers */
 
 #if PF_TRANSPARENT
