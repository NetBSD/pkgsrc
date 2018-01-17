$NetBSD: patch-src_corelib_thread_qwaitcondition__unix.cpp,v 1.2 2018/01/17 19:30:47 markd Exp $

On NetBSD before 6.1, do not use pthread_condattr_setclock().

--- src/corelib/thread/qwaitcondition_unix.cpp.orig	2017-05-26 12:43:31.000000000 +0000
+++ src/corelib/thread/qwaitcondition_unix.cpp
@@ -52,6 +52,7 @@
 
 #include <errno.h>
 #include <sys/time.h>
+#include <sys/param.h>
 #include <time.h>
 
 #ifndef QT_NO_THREAD
@@ -84,7 +85,7 @@ void qt_initialize_pthread_cond(pthread_
 #if defined(Q_OS_ANDROID)
     if (local_condattr_setclock && QElapsedTimer::clockType() == QElapsedTimer::MonotonicClock)
         local_condattr_setclock(&condattr, CLOCK_MONOTONIC);
-#elif !defined(Q_OS_MAC)
+#elif !defined(Q_OS_MAC) && !(defined(Q_OS_NETBSD) && (__NetBSD_Version__ < 600010000))
     if (QElapsedTimer::clockType() == QElapsedTimer::MonotonicClock)
         pthread_condattr_setclock(&condattr, CLOCK_MONOTONIC);
 #endif
