$NetBSD: patch-src_qml_jsruntime_qv4engine.cpp,v 1.3 2016/01/28 16:58:18 fhajny Exp $

Get stack address/size on SunOS.

--- src/qml/jsruntime/qv4engine.cpp.orig	2015-10-13 04:37:50.000000000 +0000
+++ src/qml/jsruntime/qv4engine.cpp
@@ -139,13 +139,21 @@ quintptr getStackLimit()
 #if HAVE(PTHREAD_NP_H) && OS(FREEBSD)
     // on FreeBSD pthread_attr_init() must be called otherwise getting the attrs crashes
     if (pthread_attr_init(&attr) == 0 && pthread_attr_get_np(pthread_self(), &attr) == 0) {
-#else
+#elif !OS(SOLARIS)
     if (pthread_getattr_np(pthread_self(), &attr) == 0) {
+#else
+    if (true) {
 #endif
         void *stackBottom = Q_NULLPTR;
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
