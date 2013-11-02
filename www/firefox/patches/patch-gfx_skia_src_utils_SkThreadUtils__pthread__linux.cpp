$NetBSD: patch-gfx_skia_src_utils_SkThreadUtils__pthread__linux.cpp,v 1.1 2013/11/02 22:57:55 ryoon Exp $

--- gfx/skia/src/utils/SkThreadUtils_pthread_linux.cpp.orig	2013-10-25 22:27:18.000000000 +0000
+++ gfx/skia/src/utils/SkThreadUtils_pthread_linux.cpp
@@ -21,11 +21,19 @@
 #define cpu_set_t cpuset_t
 #endif
 
+#if defined(__NetBSD__)
+#define CPU_SETSIZE 1024
+#endif
+
 #ifndef CPU_COUNT
 static int CPU_COUNT(cpu_set_t *set) {
     int count = 0;
     for (int i = 0; i < CPU_SETSIZE; i++) {
+#if defined(__NetBSD__)
+	if (cpuset_isset(i, set)) {
+#else
         if (CPU_ISSET(i, set)) {
+#endif
             count++;
 	}
     }
@@ -36,7 +44,11 @@ static int CPU_COUNT(cpu_set_t *set) {
 static int nth_set_cpu(unsigned int n, cpu_set_t* cpuSet) {
     n %= CPU_COUNT(cpuSet);
     for (unsigned int setCpusSeen = 0, currentCpu = 0; true; ++currentCpu) {
+#if defined(__NetBSD__)
+        if (cpuset_isset(currentCpu, cpuSet)) {
+#else
         if (CPU_ISSET(currentCpu, cpuSet)) {
+#endif
             ++setCpusSeen;
             if (setCpusSeen > n) {
                 return currentCpu;
@@ -51,15 +63,31 @@ bool SkThread::setProcessorAffinity(unsi
         return false;
     }
 
+#if defined(__NetBSD__)
+    cpu_set_t *parentCpuset;
+    if (0 != pthread_getaffinity_np(pthread_self(), sizeof(cpu_set_t *), parentCpuset)) {
+#else
     cpu_set_t parentCpuset;
     if (0 != pthread_getaffinity_np(pthread_self(), sizeof(cpu_set_t), &parentCpuset)) {
+#endif
         return false;
     }
 
+#if defined(__NetBSD__)
+    cpu_set_t *cpuset;
+    cpuset_zero(cpuset);
+    cpuset_set(nth_set_cpu(processor, parentCpuset), cpuset);
+#else
     cpu_set_t cpuset;
     CPU_ZERO(&cpuset);
     CPU_SET(nth_set_cpu(processor, &parentCpuset), &cpuset);
+#endif
     return 0 == pthread_setaffinity_np(pthreadData->fPThread,
+#if defined(__NetBSD__)
+                                       sizeof(cpu_set_t *),
+                                       cpuset);
+#else
                                        sizeof(cpu_set_t),
                                        &cpuset);
+#endif
 }
