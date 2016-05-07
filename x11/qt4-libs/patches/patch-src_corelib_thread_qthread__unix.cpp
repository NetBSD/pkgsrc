$NetBSD: patch-src_corelib_thread_qthread__unix.cpp,v 1.1.8.1 2016/05/07 19:25:22 bsiegert Exp $

--- src/corelib/thread/qthread_unix.cpp.orig	2015-06-23 15:32:25.000000000 +0000
+++ src/corelib/thread/qthread_unix.cpp
@@ -120,6 +120,12 @@ enum { ThreadPriorityResetFlag = 0x80000
 #if defined(Q_CC_XLC) || defined (Q_CC_SUN)
 #define HAVE_TLS
 #endif
+#if defined(Q_OS_NETBSD)
+#include <machine/types.h>
+#if defined(__HAVE_TLS_VARIANT_I) || defined(__HAVE_TLS_VARIANT_II)
+#define HAVE_TLS
+#endif
+#endif
 
 #ifdef HAVE_TLS
 static __thread QThreadData *currentThreadData = 0;
