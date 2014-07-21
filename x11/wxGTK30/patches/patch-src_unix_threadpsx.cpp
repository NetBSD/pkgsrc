$NetBSD: patch-src_unix_threadpsx.cpp,v 1.1 2014/07/21 06:53:24 dbj Exp $
tweak use of thread priority functions

--- src/unix/threadpsx.cpp.orig	2014-06-14 21:48:48.000000000 +0000
+++ src/unix/threadpsx.cpp
@@ -69,6 +69,13 @@
 #define THR_ID_CAST(id)  (reinterpret_cast<void*>(id))
 #define THR_ID(thr)      THR_ID_CAST((thr)->GetId())
 
+#ifdef __NetBSD__
+#include <sys/param.h>
+#if __NetBSD_Version__ < 499005000 && defined(HAVE_THREAD_PRIORITY_FUNCTIONS)
+#undef HAVE_THREAD_PRIORITY_FUNCTIONS
+#endif
+#endif
+
 // ----------------------------------------------------------------------------
 // constants
 // ----------------------------------------------------------------------------
