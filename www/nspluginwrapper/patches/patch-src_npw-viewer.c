$NetBSD: patch-src_npw-viewer.c,v 1.1 2015/10/24 06:30:40 tsutsui Exp $

Disable use_cache which seems to cause weird behavior.

--- src/npw-viewer.c.orig	2011-07-01 03:18:57.000000000 +0000
+++ src/npw-viewer.c
@@ -56,7 +56,11 @@
 #define USE_XEMBED_HACK 1
 
 // Define to use NPIdentifier cache
+#if defined(BUILD_GENERIC)
+#define USE_NPIDENTIFIER_CACHE 0
+#else
 #define USE_NPIDENTIFIER_CACHE 1
+#endif
 #define NPIDENTIFIER_CACHE_SIZE 256
 
 // RPC global connections
