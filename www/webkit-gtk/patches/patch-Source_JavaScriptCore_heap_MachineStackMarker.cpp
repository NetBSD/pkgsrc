$NetBSD: patch-Source_JavaScriptCore_heap_MachineStackMarker.cpp,v 1.5 2017/04/13 16:58:14 jperkin Exp $

SunOS compatibility, though newer illumos has pthread_getattr_np so we should
really add functionality tests for it and use it where available.

--- Source/JavaScriptCore/heap/MachineStackMarker.cpp.orig	2016-08-22 12:21:07.000000000 +0000
+++ Source/JavaScriptCore/heap/MachineStackMarker.cpp
@@ -52,11 +52,7 @@
 #include <sys/mman.h>
 #include <unistd.h>
 
-#if OS(SOLARIS)
-#include <thread.h>
-#else
 #include <pthread.h>
-#endif
 
 #if HAVE(PTHREAD_NP_H)
 #include <pthread_np.h>
@@ -488,7 +484,7 @@ size_t MachineThreads::Thread::getRegist
     // e.g. on FreeBSD 5.4, neundorf@kde.org
     pthread_attr_get_np(platformThread, &regs.attribute);
 #endif
-#else
+#elif !OS(SOLARIS)
     // FIXME: this function is non-portable; other POSIX systems may have different np alternatives
     pthread_getattr_np(platformThread, &regs.attribute);
 #endif
