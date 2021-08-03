$NetBSD: patch-src_3rdparty_chromium_v8_src_base_platform_platform-posix.cc,v 1.1 2021/08/03 21:04:36 markd Exp $

--- src/3rdparty/chromium/v8/src/base/platform/platform-posix.cc.orig	2020-07-15 19:01:43.000000000 +0000
+++ src/3rdparty/chromium/v8/src/base/platform/platform-posix.cc
@@ -25,6 +25,9 @@
     defined(__NetBSD__) || defined(__OpenBSD__)
 #include <sys/sysctl.h>  // NOLINT, for sysctl
 #endif
+#if defined(__NetBSD__)
+#include <lwp.h>
+#endif
 
 #if defined(ANDROID) && !defined(V8_ANDROID_LOG_STDOUT)
 #define LOG_TAG "v8"
@@ -433,7 +436,7 @@ bool OS::DiscardSystemPages(void* addres
 
 // static
 bool OS::HasLazyCommits() {
-#if V8_OS_AIX || V8_OS_LINUX || V8_OS_MACOSX
+#if V8_OS_AIX || V8_OS_LINUX || V8_OS_MACOSX || V8_OS_FREEBSD || V8_OS_NETBSD
   return true;
 #else
   // TODO(bbudge) Return true for all POSIX platforms.
@@ -568,6 +571,10 @@ int OS::GetCurrentThreadId() {
   return static_cast<int>(thread_self());
 #elif V8_OS_FUCHSIA
   return static_cast<int>(zx_thread_self());
+#elif V8_OS_FREEBSD
+  return static_cast<int>(pthread_getthreadid_np());
+#elif V8_OS_NETBSD
+  return static_cast<int>(_lwp_self());
 #elif V8_OS_SOLARIS
   return static_cast<int>(pthread_self());
 #else
@@ -756,9 +763,15 @@ Thread::Thread(const Options& options)
     : data_(new PlatformData),
       stack_size_(options.stack_size()),
       start_semaphore_(nullptr) {
+#if !defined(V8_OS_NETBSD)
   if (stack_size_ > 0 && static_cast<size_t>(stack_size_) < PTHREAD_STACK_MIN) {
     stack_size_ = PTHREAD_STACK_MIN;
   }
+#else
+  if (stack_size_ > 0 && static_cast<size_t>(stack_size_) < static_cast<size_t>(sysconf(_SC_THREAD_STACK_MIN))) {
+    stack_size_ = sysconf(_SC_THREAD_STACK_MIN);
+  }
+#endif
   set_name(options.name());
 }
 
@@ -773,7 +786,7 @@ static void SetThreadName(const char* na
   pthread_set_name_np(pthread_self(), name);
 #elif V8_OS_NETBSD
   STATIC_ASSERT(Thread::kMaxThreadNameLength <= PTHREAD_MAX_NAMELEN_NP);
-  pthread_setname_np(pthread_self(), "%s", name);
+  pthread_setname_np(pthread_self(), "%s", (void *)name);
 #elif V8_OS_MACOSX
   // pthread_setname_np is only available in 10.6 or later, so test
   // for it at runtime.
