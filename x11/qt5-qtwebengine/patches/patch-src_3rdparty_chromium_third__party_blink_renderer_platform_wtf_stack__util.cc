$NetBSD: patch-src_3rdparty_chromium_third__party_blink_renderer_platform_wtf_stack__util.cc,v 1.1 2021/08/03 21:04:35 markd Exp $

--- src/3rdparty/chromium/third_party/blink/renderer/platform/wtf/stack_util.cc.orig	2020-07-15 18:56:04.000000000 +0000
+++ src/3rdparty/chromium/third_party/blink/renderer/platform/wtf/stack_util.cc
@@ -18,6 +18,13 @@
 extern "C" void* __libc_stack_end;  // NOLINT
 #endif
 
+#if defined(OS_FREEBSD)
+#include <pthread_np.h>
+#endif
+#if defined(OS_BSD)
+#include <sys/signal.h>
+#endif
+
 namespace WTF {
 
 size_t GetUnderestimatedStackSize() {
@@ -29,7 +36,7 @@ size_t GetUnderestimatedStackSize() {
 // FIXME: On Mac OSX and Linux, this method cannot estimate stack size
 // correctly for the main thread.
 
-#elif defined(__GLIBC__) || defined(OS_ANDROID) || defined(OS_FREEBSD) || \
+#elif defined(__GLIBC__) || defined(OS_ANDROID) || defined(OS_BSD) || \
     defined(OS_FUCHSIA)
   // pthread_getattr_np() can fail if the thread is not invoked by
   // pthread_create() (e.g., the main thread of blink_unittests).
@@ -97,7 +104,7 @@ return Threading::ThreadStackSize();
 }
 
 void* GetStackStart() {
-#if defined(__GLIBC__) || defined(OS_ANDROID) || defined(OS_FREEBSD) || \
+#if defined(__GLIBC__) || defined(OS_ANDROID) || defined(OS_BSD) || \
     defined(OS_FUCHSIA)
   pthread_attr_t attr;
   int error;
