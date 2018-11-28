$NetBSD: patch-kitty_threading.h,v 1.1 2018/11/28 18:48:58 nia Exp $

Support NetBSD.

--- kitty/threading.h.orig	2018-09-29 03:45:40.000000000 +0000
+++ kitty/threading.h
@@ -14,6 +14,8 @@
 #if defined(__APPLE__)
 // I cant figure out how to get pthread.h to include this definition on macOS. MACOSX_DEPLOYMENT_TARGET does not work.
 extern int pthread_setname_np(const char *name);
+#elif defined(__NetBSD__)
+extern int pthread_getname_np(pthread_t, char *, size_t);
 #elif defined(FREEBSD_SET_NAME)
 // Function has a different name on FreeBSD
 void pthread_set_name_np(pthread_t tid, const char *name);
@@ -27,6 +29,8 @@ set_thread_name(const char *name) {
     int ret;
 #if defined(__APPLE__)
     ret = pthread_setname_np(name);
+#elif defined(__NetBSD__)
+    ret = pthread_setname_np(pthread_self(), name, NULL);
 #elif defined(FREEBSD_SET_NAME)
     pthread_set_name_np(pthread_self(), name);
     ret = 0;
