$NetBSD: patch-bin_varnishd_cache_cache__panic.c,v 1.1 2021/06/25 12:21:08 tnn Exp $

Need sys/cdefs.h for __BEGIN_DECLS/__END_DECLS.

--- bin/varnishd/cache/cache_panic.c.orig	2021-03-12 15:02:41.000000000 +0000
+++ bin/varnishd/cache/cache_panic.c
@@ -31,6 +31,10 @@
 
 #include "config.h"
 
+#ifdef __NetBSD__
+#include <sys/cdefs.h>
+#endif
+
 #ifdef WITH_UNWIND
 #  include <libunwind.h>
 #else
