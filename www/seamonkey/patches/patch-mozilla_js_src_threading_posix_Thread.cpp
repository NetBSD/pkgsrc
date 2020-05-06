$NetBSD: patch-mozilla_js_src_threading_posix_Thread.cpp,v 1.1 2020/05/06 14:34:53 ryoon Exp $

--- mozilla/js/src/threading/posix/Thread.cpp.orig	2020-02-17 23:37:55.000000000 +0000
+++ mozilla/js/src/threading/posix/Thread.cpp
@@ -161,6 +161,8 @@ js::ThisThread::SetName(const char* name
   rv = 0;
 #elif defined(__NetBSD__)
   rv = pthread_setname_np(pthread_self(), "%s", (void*)name);
+#elif defined(__sun)
+  rv = 0;
 #else
   rv = pthread_setname_np(pthread_self(), name);
 #endif
