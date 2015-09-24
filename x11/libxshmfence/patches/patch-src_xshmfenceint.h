$NetBSD: patch-src_xshmfenceint.h,v 1.1 2015/09/24 23:34:16 tnn Exp $

--- src/xshmfenceint.h.orig	2013-12-02 21:07:56.000000000 +0000
+++ src/xshmfenceint.h
@@ -32,6 +32,10 @@
 #include "xshmfence_futex.h"
 #endif
 
+#if HAVE_SEMAPHORE
+#include "xshmfence_semaphore.h"
+#endif
+
 #if HAVE_PTHREAD
 #include "xshmfence_pthread.h"
 #endif
