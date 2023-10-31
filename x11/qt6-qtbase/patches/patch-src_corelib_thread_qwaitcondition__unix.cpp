$NetBSD: patch-src_corelib_thread_qwaitcondition__unix.cpp,v 1.3 2023/10/31 19:56:48 adam Exp $

On NetBSD before 6.1, do not use pthread_condattr_setclock().

--- src/corelib/thread/qwaitcondition_unix.cpp.orig	2023-09-13 16:02:48.000000000 +0000
+++ src/corelib/thread/qwaitcondition_unix.cpp
@@ -17,6 +17,7 @@
 
 #include <errno.h>
 #include <sys/time.h>
+#include <sys/param.h>
 #include <time.h>
 
 QT_BEGIN_NAMESPACE
@@ -56,7 +57,7 @@ static void qt_initialize_pthread_cond(p
 {
     pthread_condattr_t *attrp = nullptr;
 
-#if defined(CLOCK_MONOTONIC) && !defined(Q_OS_DARWIN)
+#if defined(CLOCK_MONOTONIC) && !defined(Q_OS_DARWIN) && !(defined(Q_OS_NETBSD) && (__NetBSD_Version__ < 600010000))
     pthread_condattr_t condattr;
     attrp = &condattr;
 
