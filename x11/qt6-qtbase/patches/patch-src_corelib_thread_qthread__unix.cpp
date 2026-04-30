$NetBSD: patch-src_corelib_thread_qthread__unix.cpp,v 1.1 2026/04/30 06:38:37 adam Exp $

Support NetBSD.

--- src/corelib/thread/qthread_unix.cpp.orig	2026-03-27 11:03:02.499247374 +0000
+++ src/corelib/thread/qthread_unix.cpp
@@ -350,6 +350,8 @@ static void setCurrentThreadName(QThread *thr, String 
         pthread_setname_np(name);
 #  elif defined(Q_OS_OPENBSD)
         pthread_set_name_np(pthread_self(), name);
+#  elif defined(Q_OS_NETBSD)
+        pthread_setname_np(pthread_self(), name, nullptr);
 #  elif defined(Q_OS_QNX) || defined(Q_OS_BSD4)
         pthread_setname_np(pthread_self(), name);
 #  else
