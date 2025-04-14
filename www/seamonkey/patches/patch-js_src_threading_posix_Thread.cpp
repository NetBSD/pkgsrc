$NetBSD: patch-js_src_threading_posix_Thread.cpp,v 1.1 2025/04/14 15:33:04 nia Exp $

Solaris does not have pthread_setname_np.

--- js/src/threading/posix/Thread.cpp.orig	2025-03-07 15:44:29.108090407 +0000
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
