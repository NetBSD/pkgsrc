$NetBSD: patch-v8_src_base_platform_platform-openbsd.cc,v 1.14 2026/01/19 16:14:23 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- v8/src/base/platform/platform-openbsd.cc.orig	2026-01-07 00:50:30.000000000 +0000
+++ v8/src/base/platform/platform-openbsd.cc
@@ -6,6 +6,9 @@
 // POSIX-compatible parts, the implementation is in platform-posix.cc.
 
 #include <pthread.h>
+#if !defined(__NetBSD__)
+#include <pthread_np.h>
+#endif
 #include <semaphore.h>
 #include <signal.h>
 #include <stdlib.h>
@@ -122,6 +125,34 @@ void OS::SignalCodeMovingGC() {
 
 void OS::AdjustSchedulingParams() {}
 
+// static
+Stack::StackSlot Stack::ObtainCurrentThreadStackStart() {
+#if defined(__NetBSD__)
+  pthread_attr_t attr;
+  int error;
+  pthread_attr_init(&attr);
+  error = pthread_attr_get_np(pthread_self(), &attr);
+  if (!error) {
+    void* base;
+    size_t size;
+    error = pthread_attr_getstack(&attr, &base, &size);
+    CHECK(!error);
+    pthread_attr_destroy(&attr);
+    return reinterpret_cast<uint8_t*>(base) + size;
+  }
+  pthread_attr_destroy(&attr);
+  return nullptr;
+#else
+  stack_t ss;
+  void *base;
+  if (pthread_stackseg_np(pthread_self(), &ss) != 0)
+    return nullptr;
+
+  base = (void*)((size_t) ss.ss_sp - ss.ss_size);
+  return reinterpret_cast<uint8_t*>(base) + ss.ss_size;
+#endif
+}
+
 std::optional<OS::MemoryRange> OS::GetFirstFreeMemoryRangeWithin(
     OS::Address boundary_start, OS::Address boundary_end, size_t minimum_size,
     size_t alignment) {
