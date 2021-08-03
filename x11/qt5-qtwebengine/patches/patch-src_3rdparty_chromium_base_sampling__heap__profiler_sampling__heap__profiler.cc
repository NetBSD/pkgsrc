$NetBSD: patch-src_3rdparty_chromium_base_sampling__heap__profiler_sampling__heap__profiler.cc,v 1.1 2021/08/03 21:04:34 markd Exp $

--- src/3rdparty/chromium/base/sampling_heap_profiler/sampling_heap_profiler.cc.orig	2020-07-08 21:41:45.000000000 +0000
+++ src/3rdparty/chromium/base/sampling_heap_profiler/sampling_heap_profiler.cc
@@ -21,7 +21,7 @@
 #include "base/trace_event/heap_profiler_allocation_context_tracker.h"
 #include "build/build_config.h"
 
-#if defined(OS_MACOSX)
+#if defined(OS_MACOSX) || defined(OS_BSD)
 #include <pthread.h>
 #endif
 
@@ -61,6 +61,14 @@ const char* GetAndLeakThreadName() {
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
 #elif defined(OS_MACOSX)
   int err = pthread_getname_np(pthread_self(), name, kBufferLen);
   if (err == 0 && *name != '\0')
