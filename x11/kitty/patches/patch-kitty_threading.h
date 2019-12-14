$NetBSD: patch-kitty_threading.h,v 1.2 2019/12/14 22:08:10 nia Exp $

Support NetBSD.

--- kitty/threading.h.orig	2019-11-27 04:25:00.000000000 +0000
+++ kitty/threading.h
@@ -17,6 +17,8 @@ extern int pthread_setname_np(const char
 #elif defined(FREEBSD_SET_NAME)
 // Function has a different name on FreeBSD
 void pthread_set_name_np(pthread_t tid, const char *name);
+#elif defined(__NetBSD__)
+int pthread_setname_np(pthread_t thread, const char *name, void *arg);
 #else
 // Need _GNU_SOURCE for pthread_setname_np on linux and that causes other issues on systems with old glibc
 extern int pthread_setname_np(pthread_t, const char *name);
@@ -30,6 +32,8 @@ set_thread_name(const char *name) {
 #elif defined(FREEBSD_SET_NAME)
     pthread_set_name_np(pthread_self(), name);
     ret = 0;
+#elif defined(__NetBSD__)
+    ret = pthread_setname_np(pthread_self(), "%s", (char *)name);
 #else
     ret = pthread_setname_np(pthread_self(), name);
 #endif
