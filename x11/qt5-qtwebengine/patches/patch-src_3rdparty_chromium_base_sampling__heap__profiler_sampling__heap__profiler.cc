$NetBSD: patch-src_3rdparty_chromium_base_sampling__heap__profiler_sampling__heap__profiler.cc,v 1.2 2022/04/18 11:18:18 adam Exp $

--- src/3rdparty/chromium/base/sampling_heap_profiler/sampling_heap_profiler.cc.orig	2021-02-19 16:41:59.000000000 +0000
+++ src/3rdparty/chromium/base/sampling_heap_profiler/sampling_heap_profiler.cc
@@ -22,7 +22,7 @@
 #include "base/trace_event/heap_profiler_allocation_context_tracker.h"  // no-presubmit-check
 #include "build/build_config.h"
 
-#if defined(OS_APPLE)
+#if defined(OS_APPLE) || defined(OS_BSD)
 #include <pthread.h>
 #endif
 
@@ -62,6 +62,14 @@ const char* GetAndLeakThreadName() {
   int err = prctl(PR_GET_NAME, name);
   if (!err)
     return strdup(name);
+#elif defined(OS_FREEBSD)
+  pthread_get_name_np(pthread_self(), name, kBufferLen);
+  if (*name != '\0')
+    return strdup(name);
+#elif defined(OS_NETBSD)
+  pthread_getname_np(pthread_self(), name, kBufferLen);
+  if (*name != '\0')
+    return strdup(name);
 #elif defined(OS_APPLE)
   int err = pthread_getname_np(pthread_self(), name, kBufferLen);
   if (err == 0 && *name != '\0')
