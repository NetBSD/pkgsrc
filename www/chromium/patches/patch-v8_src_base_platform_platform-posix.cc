$NetBSD: patch-v8_src_base_platform_platform-posix.cc,v 1.33 2026/11/19 19:46:12 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- v8/src/base/platform/platform-posix.cc.orig	2026-11-11 21:01:38.000000000 +0000
+++ v8/src/base/platform/platform-posix.cc
@@ -77,9 +77,11 @@
 #include <sys/syscall.h>
 #endif
 
-#if V8_OS_FREEBSD || V8_OS_DARWIN || V8_OS_OPENBSD || V8_OS_SOLARIS
+#if V8_OS_FREEBSD || V8_OS_DARWIN || V8_OS_BSD || V8_OS_SOLARIS
+#ifndef MAP_ANONYMOUS
 #define MAP_ANONYMOUS MAP_ANON
 #endif
+#endif
 
 /*
  * NOTE: illumos starting with illumos#14418 (pushed April 20th, 2022)
@@ -370,6 +372,13 @@ void OS::SetRandomMmapSeed(int64_t seed)
   }
 }
 
+#if V8_OS_OPENBSD
+// Allow OpenBSD's mmap to select a random address on OpenBSD
+// static
+void* OS::GetRandomMmapAddr() {
+  return nullptr;
+}
+#else
 // static
 void* OS::GetRandomMmapAddr() {
   uintptr_t raw_addr;
@@ -468,6 +477,7 @@ void* OS::GetRandomMmapAddr() {
 #endif
   return reinterpret_cast<void*>(raw_addr);
 }
+#endif
 
 // TODO(bbudge) Move Cygwin and Fuchsia stuff into platform-specific files.
 #if !V8_OS_CYGWIN && !V8_OS_FUCHSIA
@@ -783,7 +793,7 @@ void OS::DestroySharedMemoryHandle(Share
 #if !V8_OS_ZOS
 // static
 bool OS::HasLazyCommits() {
-#if V8_OS_AIX || V8_OS_LINUX || V8_OS_DARWIN
+#if V8_OS_AIX || V8_OS_LINUX || V8_OS_DARWIN || V8_OS_BSD
   return true;
 #else
   // TODO(bbudge) Return true for all POSIX platforms.
@@ -1234,7 +1244,11 @@ Thread::Thread(const Options& options)
       stack_size_(options.stack_size()),
       priority_(options.priority()),
       start_semaphore_(nullptr) {
+#if !defined(V8_OS_NETBSD)
   const int min_stack_size = static_cast<int>(PTHREAD_STACK_MIN);
+#else
+  const int min_stack_size = static_cast<int>(sysconf(_SC_THREAD_STACK_MIN));
+#endif
   if (stack_size_ > 0) stack_size_ = std::max(stack_size_, min_stack_size);
   set_name(options.name());
 }
@@ -1249,7 +1263,7 @@ static void SetThreadName(const char* na
   pthread_set_name_np(pthread_self(), name);
 #elif V8_OS_NETBSD
   static_assert(Thread::kMaxThreadNameLength <= PTHREAD_MAX_NAMELEN_NP);
-  pthread_setname_np(pthread_self(), "%s", name);
+  pthread_setname_np(pthread_self(), "%s", (void *)name);
 #elif V8_OS_DARWIN
   // pthread_setname_np is only available in 10.6 or later, so test
   // for it at runtime.
@@ -1426,7 +1440,7 @@ void Thread::SetThreadLocal(LocalStorage
 // keep this version in POSIX as most Linux-compatible derivatives will
 // support it. MacOS and FreeBSD are different here.
 #if !defined(V8_OS_FREEBSD) && !defined(V8_OS_DARWIN) && !defined(_AIX) && \
-    !defined(V8_OS_SOLARIS)
+    !defined(V8_OS_SOLARIS) && !defined(V8_OS_OPENBSD) && !defined(V8_OS_NETBSD)
 
 namespace {
 #if DEBUG
@@ -1488,19 +1502,13 @@ Stack::StackSlot Stack::ObtainCurrentThr
   return stack_start;
 #endif  // V8_OS_ZOS
 }
+#endif  // !defined(V8_OS_FREEBSD) && !defined(V8_OS_DARWIN) &&
+        // !defined(_AIX) && !defined(V8_OS_SOLARIS)
 
 // static
 Stack::StackSlot Stack::ObtainCurrentThreadStackReservedLimit() {
 #if V8_OS_ZOS
   return nullptr;
-#elif V8_OS_OPENBSD
-  stack_t stack;
-  int error = pthread_stackseg_np(pthread_self(), &stack);
-  if (error) {
-    DCHECK(MainThreadIsCurrentThread());
-    return nullptr;
-  }
-  return stack.ss_sp;
 #else
 // For most libcs, pthread_getattr_np() returns the the stack reserved
 // limit on the main thread, but musl only returns the current high-water
@@ -1511,7 +1519,11 @@ Stack::StackSlot Stack::ObtainCurrentThr
   if (syscall(__NR_gettid) == getpid()) return nullptr;
 #endif
   pthread_attr_t attr;
+#if V8_OS_BSD
+  int error = pthread_attr_init(&attr);
+#else
   int error = pthread_getattr_np(pthread_self(), &attr);
+#endif
   if (error) {
     DCHECK(MainThreadIsCurrentThread());
     return nullptr;
@@ -1525,10 +1537,6 @@ Stack::StackSlot Stack::ObtainCurrentThr
 #endif  // V8_OS_ZOS
 }
 
-#endif  // !defined(V8_OS_FREEBSD) && !defined(V8_OS_DARWIN) &&
-        // !defined(_AIX) && !defined(V8_OS_SOLARIS)
-
-
 
 // static
 void Stack::SetCurrentThreadStackBounds(uintptr_t, uintptr_t) { UNREACHABLE(); }
