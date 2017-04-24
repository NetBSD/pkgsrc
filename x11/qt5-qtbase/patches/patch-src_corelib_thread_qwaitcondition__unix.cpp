$NetBSD: patch-src_corelib_thread_qwaitcondition__unix.cpp,v 1.1 2017/04/24 12:27:58 maya Exp $

don't have pthread_condattr_setclock on NetBSD < 6.1, don't
use it.

--- src/corelib/thread/qwaitcondition_unix.cpp.orig	2015-10-13 04:35:30.000000000 +0000
+++ src/corelib/thread/qwaitcondition_unix.cpp
@@ -45,6 +45,7 @@
 
 #include <errno.h>
 #include <sys/time.h>
+#include <sys/param.h>
 #include <time.h>
 
 #ifndef QT_NO_THREAD
@@ -77,7 +78,10 @@ void qt_initialize_pthread_cond(pthread_
 #if defined(Q_OS_ANDROID)
     if (local_condattr_setclock && QElapsedTimer::clockType() == QElapsedTimer::MonotonicClock)
         local_condattr_setclock(&condattr, CLOCK_MONOTONIC);
-#elif !defined(Q_OS_MAC) && !defined(Q_OS_HAIKU)
+#elif (defined(Q_OS_NETBSD) && (__NetBSD_Version__ < 600010000)) || \
+    defined(Q_OS_MAC) || defined(Q_OS_HAIKU)
+    /* nothing, don't have pthread_condattr_setclock */
+#else
     if (QElapsedTimer::clockType() == QElapsedTimer::MonotonicClock)
         pthread_condattr_setclock(&condattr, CLOCK_MONOTONIC);
 #endif
