$NetBSD: patch-js_src_threading_posix_Thread.cpp,v 1.1 2018/06/26 09:37:10 jperkin Exp $

Support SunOS.

--- js/src/threading/posix/Thread.cpp.orig	2018-06-05 19:47:32.000000000 +0000
+++ js/src/threading/posix/Thread.cpp
@@ -194,6 +194,8 @@ js::ThisThread::SetName(const char* name
   rv = 0;
 #elif defined(__NetBSD__)
   rv = pthread_setname_np(pthread_self(), "%s", (void*)name);
+#elif defined(__sun)
+  rv = 0;
 #else
   rv = pthread_setname_np(pthread_self(), name);
 #endif
