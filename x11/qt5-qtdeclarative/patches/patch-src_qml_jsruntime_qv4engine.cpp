$NetBSD: patch-src_qml_jsruntime_qv4engine.cpp,v 1.1 2014/12/30 17:23:46 adam Exp $

Get stack address/size on SunOS.

--- src/qml/jsruntime/qv4engine.cpp.orig	2014-09-11 10:48:29.000000000 +0000
+++ src/qml/jsruntime/qv4engine.cpp
@@ -118,11 +118,17 @@ quintptr getStackLimit()
     pthread_attr_t attr;
 #if HAVE(PTHREAD_NP_H) && OS(FREEBSD)
     if (pthread_attr_get_np(pthread_self(), &attr) == 0) {
-#else
+#elif !OS(SOLARIS)
     if (pthread_getattr_np(pthread_self(), &attr) == 0) {
 #endif
         size_t stackSize = 0;
+#if OS(SOLARIS)
+        pthread_attr_init(&attr);
+        pthread_attr_getstackaddr(&attr, &stackBottom);
+        pthread_attr_getstacksize(&attr, &stackSize);
+#else
         pthread_attr_getstack(&attr, &stackBottom, &stackSize);
+#endif
         pthread_attr_destroy(&attr);
 
 #        if defined(Q_OS_ANDROID)
