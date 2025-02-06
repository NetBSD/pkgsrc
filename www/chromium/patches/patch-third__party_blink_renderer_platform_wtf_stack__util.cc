$NetBSD: patch-third__party_blink_renderer_platform_wtf_stack__util.cc,v 1.1 2025/02/06 09:58:24 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/blink/renderer/platform/wtf/stack_util.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ third_party/blink/renderer/platform/wtf/stack_util.cc
@@ -23,6 +23,13 @@
 extern "C" void* __libc_stack_end;  // NOLINT
 #endif
 
+#if BUILDFLAG(IS_BSD)
+#include <sys/signal.h>
+#if !BUILDFLAG(IS_NETBSD)
+#include <pthread_np.h>
+#endif
+#endif
+
 namespace WTF {
 
 size_t GetUnderestimatedStackSize() {
@@ -35,7 +42,8 @@ size_t GetUnderestimatedStackSize() {
 // correctly for the main thread.
 
 #elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || \
-    BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_FREEBSD) || BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_FREEBSD) || BUILDFLAG(IS_FUCHSIA) || \
+    BUILDFLAG(IS_NETBSD)
   // pthread_getattr_np() can fail if the thread is not invoked by
   // pthread_create() (e.g., the main thread of blink_unittests).
   // If so, a conservative size estimate is returned.
@@ -56,7 +64,7 @@ size_t GetUnderestimatedStackSize() {
     pthread_attr_destroy(&attr);
     return size;
   }
-#if BUILDFLAG(IS_FREEBSD)
+#if BUILDFLAG(IS_FREEBSD) || BUILDFLAG(IS_NETBSD)
   pthread_attr_destroy(&attr);
 #endif
 
@@ -67,6 +75,8 @@ size_t GetUnderestimatedStackSize() {
   //    low as 512k.
   //
   return 512 * 1024;
+#elif BUILDFLAG(IS_OPENBSD)
+  return 512 * 1024;
 #elif BUILDFLAG(IS_APPLE)
   // pthread_get_stacksize_np() returns too low a value for the main thread on
   // OSX 10.9,
@@ -103,7 +113,7 @@ size_t GetUnderestimatedStackSize() {
 
 void* GetStackStart() {
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || \
-    BUILDFLAG(IS_FREEBSD) || BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_FREEBSD) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_NETBSD)
   pthread_attr_t attr;
   int error;
 #if BUILDFLAG(IS_FREEBSD)
@@ -120,7 +130,7 @@ void* GetStackStart() {
     pthread_attr_destroy(&attr);
     return reinterpret_cast<uint8_t*>(base) + size;
   }
-#if BUILDFLAG(IS_FREEBSD)
+#if BUILDFLAG(IS_FREEBSD) || BUILDFLAG(IS_NETBSD)
   pthread_attr_destroy(&attr);
 #endif
 #if defined(__GLIBC__)
@@ -154,6 +164,13 @@ void* GetStackStart() {
   ::GetCurrentThreadStackLimits(&lowLimit, &highLimit);
   return reinterpret_cast<void*>(highLimit);
 #endif
+#elif BUILDFLAG(IS_OPENBSD)
+  stack_t ss;
+  void *base;
+  int error = pthread_stackseg_np(pthread_self(), &ss);
+  CHECK(!error);
+  base = (void*)((size_t) ss.ss_sp - ss.ss_size);
+  return reinterpret_cast<uint8_t*>(base) + ss.ss_size;
 #else
 #error Unsupported getStackStart on this platform.
 #endif
