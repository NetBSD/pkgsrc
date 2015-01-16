$NetBSD: patch-src_ip_Intercept.cc,v 1.3 2015/01/16 11:41:11 adam Exp $

Avoid conflict with IP Fitler's debug().

--- src/ip/Intercept.cc.orig	2015-01-13 11:53:17.000000000 +0000
+++ src/ip/Intercept.cc
@@ -42,6 +42,10 @@
 
 #if IPF_TRANSPARENT
 
+#ifdef debug
+#undef debug		// XXX: IP Filter might declare debug().
+#endif
+
 #if !defined(IPFILTER_VERSION)
 #define IPFILTER_VERSION        5000004
 #endif
@@ -92,6 +96,10 @@
 #include <errno.h>
 #endif
 
+// Stolen from src/defines.h
+#define debug(SECTION, LEVEL) \
+        do_debug(SECTION, LEVEL) ? (void) 0 : _db_print
+
 #endif /* IPF_TRANSPARENT required headers */
 
 #if PF_TRANSPARENT
