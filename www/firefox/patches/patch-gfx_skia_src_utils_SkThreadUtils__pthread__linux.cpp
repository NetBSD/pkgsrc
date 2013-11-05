$NetBSD: patch-gfx_skia_src_utils_SkThreadUtils__pthread__linux.cpp,v 1.2 2013/11/05 14:20:41 ryoon Exp $

--- gfx/skia/src/utils/SkThreadUtils_pthread_linux.cpp.orig	2013-10-25 22:27:18.000000000 +0000
+++ gfx/skia/src/utils/SkThreadUtils_pthread_linux.cpp
@@ -12,26 +12,47 @@
 #include "SkThreadUtils.h"
 #include "SkThreadUtils_pthread.h"
 
+#include <unistd.h>
 #include <pthread.h>
 #ifdef __FreeBSD__
 #include <pthread_np.h>
 #endif
+#ifdef __NetBSD__
+#include <sched.h>
+#endif
 
 #if defined(__FreeBSD__) || defined(__NetBSD__)
 #define cpu_set_t cpuset_t
 #endif
 
-#ifndef CPU_COUNT
+#if !defined(CPU_COUNT) && !defined(__NetBSD__)
 static int CPU_COUNT(cpu_set_t *set) {
     int count = 0;
     for (int i = 0; i < CPU_SETSIZE; i++) {
         if (CPU_ISSET(i, set)) {
             count++;
-	}
+        }
+    }
+    return count;
+}
+#endif
+
+#if defined(__NetBSD__)
+
+#define CPU_ISSET(c, s) cpuset_isset(c, s)
+
+static int CPU_COUNT(cpuset_t *set) {
+    static const int ncpu = sysconf(_SC_NPROCESSORS_CONF);
+    int count = 0;
+
+    for (int i = 0; i < ncpu; i++) {
+        if (cpuset_isset(i, set)) {
+            count++;
+        }
     }
     return count;
 }
-#endif /* !CPU_COUNT */
+#endif
 
 static int nth_set_cpu(unsigned int n, cpu_set_t* cpuSet) {
     n %= CPU_COUNT(cpuSet);
@@ -51,6 +72,7 @@ bool SkThread::setProcessorAffinity(unsi
         return false;
     }
 
+#if !defined(__NetBSD__)
     cpu_set_t parentCpuset;
     if (0 != pthread_getaffinity_np(pthread_self(), sizeof(cpu_set_t), &parentCpuset)) {
         return false;
@@ -62,4 +84,23 @@ bool SkThread::setProcessorAffinity(unsi
     return 0 == pthread_setaffinity_np(pthreadData->fPThread,
                                        sizeof(cpu_set_t),
                                        &cpuset);
+#else
+    cpuset_t *cpuset = cpuset_create();
+    if (!cpuset) {
+        return false;
+    }
+    size_t csize = cpuset_size(cpuset);
+    if (0 != pthread_getaffinity_np(pthread_self(), csize, cpuset)) {
+        cpuset_destroy(cpuset);
+        return false;
+    }
+
+    int nthcpu = nth_set_cpu(processor, cpuset);
+    cpuset_zero(cpuset);
+    cpuset_set(nthcpu, cpuset);
+
+    bool ok = 0 == pthread_setaffinity_np(pthreadData->fPThread, csize, cpuset);
+    cpuset_destroy(cpuset);
+    return ok;
+#endif
 }
