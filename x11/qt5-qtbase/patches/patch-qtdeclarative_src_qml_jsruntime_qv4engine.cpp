$NetBSD: patch-qtdeclarative_src_qml_jsruntime_qv4engine.cpp,v 1.1 2014/07/14 16:32:14 jperkin Exp $

Get stack address/size on SunOS.

--- qtdeclarative/src/qml/jsruntime/qv4engine.cpp.orig	2014-02-01 20:38:02.000000000 +0000
+++ qtdeclarative/src/qml/jsruntime/qv4engine.cpp
@@ -109,9 +109,15 @@ quintptr getStackLimit()
 #  else
     void* stackBottom = 0;
     pthread_attr_t attr;
-    pthread_getattr_np(pthread_self(), &attr);
     size_t stackSize = 0;
+#    if OS(SOLARIS)
+    pthread_attr_init(&attr);
+    pthread_attr_getstackaddr(&attr, &stackBottom);
+    pthread_attr_getstacksize(&attr, &stackSize);
+#    else
+    pthread_getattr_np(pthread_self(), &attr);
     pthread_attr_getstack(&attr, &stackBottom, &stackSize);
+#    endif
     pthread_attr_destroy(&attr);
 
 #    if defined(Q_OS_ANDROID)
