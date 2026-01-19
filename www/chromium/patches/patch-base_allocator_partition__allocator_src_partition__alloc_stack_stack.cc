$NetBSD: patch-base_allocator_partition__allocator_src_partition__alloc_stack_stack.cc,v 1.14 2026/01/19 16:14:06 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- base/allocator/partition_allocator/src/partition_alloc/stack/stack.cc.orig	2026-01-07 00:50:30.000000000 +0000
+++ base/allocator/partition_allocator/src/partition_alloc/stack/stack.cc
@@ -23,6 +23,10 @@
 #include <pthread.h>
 #endif
 
+#if PA_BUILDFLAG(IS_BSD) && !PA_BUILDFLAG(IS_NETBSD)
+#include <pthread_np.h>
+#endif
+
 #if PA_BUILDFLAG(PA_LIBC_GLIBC)
 extern "C" void* __libc_stack_end;
 #endif
@@ -55,6 +59,36 @@ void* GetStackTop() {
   return pthread_get_stackaddr_np(pthread_self());
 }
 
+#elif PA_BUILDFLAG(IS_OPENBSD)
+
+void* GetStackTop() {
+  stack_t ss;
+  if (pthread_stackseg_np(pthread_self(), &ss) != 0)
+    return nullptr;
+  return reinterpret_cast<uint8_t*>(ss.ss_sp);
+}
+
+#elif PA_BUILDFLAG(IS_FREEBSD) || PA_BUILDFLAG(IS_NETBSD)
+
+void* GetStackTop() {
+   pthread_attr_t attr;
+   int error = pthread_attr_init(&attr);
+   if (error) {
+     return nullptr;
+   }
+   error = pthread_attr_get_np(pthread_self(), &attr);
+   if (!error) {
+     void* base;
+     size_t size;
+     error = pthread_attr_getstack(&attr, &base, &size);
+     PA_CHECK(!error);
+     pthread_attr_destroy(&attr);
+     return reinterpret_cast<uint8_t*>(base) + size;
+   }
+  pthread_attr_destroy(&attr);
+  return nullptr;
+}
+
 #elif PA_BUILDFLAG(IS_POSIX) || PA_BUILDFLAG(IS_FUCHSIA)
 
 void* GetStackTop() {
