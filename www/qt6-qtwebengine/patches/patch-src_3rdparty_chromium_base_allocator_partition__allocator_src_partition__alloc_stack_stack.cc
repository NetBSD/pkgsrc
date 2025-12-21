$NetBSD: patch-src_3rdparty_chromium_base_allocator_partition__allocator_src_partition__alloc_stack_stack.cc,v 1.1 2025/12/21 09:38:12 markd Exp $

* Based on OpenBSD's qt6-qtwebengine patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/base/allocator/partition_allocator/src/partition_alloc/stack/stack.cc.orig	2025-05-29 01:27:28.000000000 +0000
+++ src/3rdparty/chromium/base/allocator/partition_allocator/src/partition_alloc/stack/stack.cc
@@ -18,6 +18,10 @@
 #include <pthread.h>
 #endif
 
+#if PA_BUILDFLAG(IS_BSD) && !PA_BUILDFLAG(IS_NETBSD)
+#include <pthread_np.h>
+#endif
+
 #if PA_BUILDFLAG(PA_LIBC_GLIBC)
 extern "C" void* __libc_stack_end;
 #endif
@@ -50,6 +54,36 @@ void* GetStackTop() {
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
