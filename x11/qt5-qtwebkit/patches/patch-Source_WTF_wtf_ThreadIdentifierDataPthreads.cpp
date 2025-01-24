$NetBSD: patch-Source_WTF_wtf_ThreadIdentifierDataPthreads.cpp,v 1.4 2025/01/24 11:54:37 wiz Exp $

* Add NetBSD support

--- Source/WTF/wtf/ThreadIdentifierDataPthreads.cpp.orig	2017-06-04 20:16:06.000000000 +0000
+++ Source/WTF/wtf/ThreadIdentifierDataPthreads.cpp
@@ -39,6 +39,12 @@
 #if OS(HURD)
 // PTHREAD_KEYS_MAX is not defined in bionic nor in Hurd, so explicitly define it here.
 #define PTHREAD_KEYS_MAX 1024
+#elif OS(NETBSD)
+#include <limits.h>
+// PTHREAD_KEYS_MAX is not defined in 5.x
+#ifndef PTHREAD_KEYS_MAX
+#define PTHREAD_KEYS_MAX 256
+#endif
 #else
 #include <limits.h>
 #endif
