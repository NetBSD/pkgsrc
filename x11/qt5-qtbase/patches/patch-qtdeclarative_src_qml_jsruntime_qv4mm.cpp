$NetBSD: patch-qtdeclarative_src_qml_jsruntime_qv4mm.cpp,v 1.1 2014/07/14 16:32:14 jperkin Exp $

SunOS needs alloca.h for alloca()
Get stack address/size on SunOS

--- qtdeclarative/src/qml/jsruntime/qv4mm.cpp.orig	2014-02-01 20:38:02.000000000 +0000
+++ qtdeclarative/src/qml/jsruntime/qv4mm.cpp
@@ -67,6 +67,10 @@
 #include <sys/storage.h>   // __tls()
 #endif
 
+#if OS(SOLARIS)
+#include <alloca.h>
+#endif
+
 QT_BEGIN_NAMESPACE
 
 using namespace QV4;
@@ -234,9 +238,15 @@ MemoryManager::MemoryManager()
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
 
     m_d->stackTop = static_cast<quintptr *>(stackBottom) + stackSize/sizeof(quintptr);
