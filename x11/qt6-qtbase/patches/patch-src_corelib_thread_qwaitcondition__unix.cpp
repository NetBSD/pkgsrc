$NetBSD: patch-src_corelib_thread_qwaitcondition__unix.cpp,v 1.2 2023/08/03 20:01:30 adam Exp $

On NetBSD before 6.1, do not use pthread_condattr_setclock().

--- src/corelib/thread/qwaitcondition_unix.cpp.orig	2023-07-06 10:02:03.000000000 +0000
+++ src/corelib/thread/qwaitcondition_unix.cpp
@@ -18,6 +18,7 @@
 
 #include <errno.h>
 #include <sys/time.h>
+#include <sys/param.h>
 #include <time.h>
 
 QT_BEGIN_NAMESPACE
@@ -33,7 +34,7 @@ void qt_initialize_pthread_cond(pthread_
     pthread_condattr_t condattr;
 
     pthread_condattr_init(&condattr);
-#if defined(CLOCK_MONOTONIC) && !defined(Q_OS_DARWIN)
+#if defined(CLOCK_MONOTONIC) && !defined(Q_OS_DARWIN) && !(defined(Q_OS_NETBSD) && (__NetBSD_Version__ < 600010000))
     if (QElapsedTimer::clockType() == QElapsedTimer::MonotonicClock)
         pthread_condattr_setclock(&condattr, CLOCK_MONOTONIC);
 #endif
