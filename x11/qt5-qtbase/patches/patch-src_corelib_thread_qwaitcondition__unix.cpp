$NetBSD: patch-src_corelib_thread_qwaitcondition__unix.cpp,v 1.3 2018/12/18 09:57:18 adam Exp $

On NetBSD before 6.1, do not use pthread_condattr_setclock().

--- src/corelib/thread/qwaitcondition_unix.cpp.orig	2018-12-03 11:15:26.000000000 +0000
+++ src/corelib/thread/qwaitcondition_unix.cpp
@@ -54,6 +54,7 @@
 
 #include <errno.h>
 #include <sys/time.h>
+#include <sys/param.h>
 #include <time.h>
 
 QT_BEGIN_NAMESPACE
@@ -84,7 +85,7 @@ void qt_initialize_pthread_cond(pthread_
 #if defined(Q_OS_ANDROID)
     if (local_condattr_setclock && QElapsedTimer::clockType() == QElapsedTimer::MonotonicClock)
         local_condattr_setclock(&condattr, CLOCK_MONOTONIC);
-#elif !defined(Q_OS_MAC)
+#elif !defined(Q_OS_MAC) && !(defined(Q_OS_NETBSD) && (__NetBSD_Version__ < 600010000))
     if (QElapsedTimer::clockType() == QElapsedTimer::MonotonicClock)
         pthread_condattr_setclock(&condattr, CLOCK_MONOTONIC);
 #endif
