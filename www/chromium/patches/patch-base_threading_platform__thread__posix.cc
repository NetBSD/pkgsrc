$NetBSD: patch-base_threading_platform__thread__posix.cc,v 1.33 2026/11/19 19:45:51 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- base/threading/platform_thread_posix.cc.orig	2026-11-11 21:01:38.000000000 +0000
+++ base/threading/platform_thread_posix.cc
@@ -6,6 +6,13 @@
 
 #include <errno.h>
 #include <pthread.h>
+#if BUILDFLAG(IS_BSD)
+#if BUILDFLAG(IS_NETBSD)
+#include <lwp.h>
+#else
+#include <pthread_np.h>
+#endif
+#endif
 #include <sched.h>
 #include <stddef.h>
 #include <stdint.h>
@@ -81,6 +88,7 @@ void* ThreadFunc(void* params) {
       base::DisallowSingleton();
     }
 
+#if !BUILDFLAG(IS_BSD)
 #if PA_BUILDFLAG(USE_PARTITION_ALLOC_AS_MALLOC)
     partition_alloc::internal::StackTopRegistry::Get().NotifyThreadCreated();
 #endif
@@ -94,6 +102,7 @@ void* ThreadFunc(void* params) {
     // where they were created. This explicitly sets the priority of all new
     // threads.
     PlatformThread::SetDefaultThreadType(thread_params->thread_type);
+#endif
   }
 
   ThreadIdNameManager::GetInstance()->RegisterThread(
@@ -271,6 +280,12 @@ PlatformThreadId PlatformThreadBase::Cur
 
 #elif BUILDFLAG(IS_POSIX) && BUILDFLAG(IS_AIX)
   return PlatformThreadId(pthread_self());
+#elif BUILDFLAG(IS_OPENBSD)
+  return PlatformThreadId(static_cast<uint64_t>(getthrid()));
+#elif BUILDFLAG(IS_FREEBSD)
+  return PlatformThreadId(static_cast<uint64_t>(pthread_getthreadid_np()));
+#elif BUILDFLAG(IS_NETBSD)
+  return PlatformThreadId(static_cast<uint64_t>(_lwp_self()));
 #elif BUILDFLAG(IS_POSIX) && !BUILDFLAG(IS_AIX)
   return PlatformThreadId(reinterpret_cast<int64_t>(pthread_self()));
 #endif
@@ -364,6 +379,9 @@ void PlatformThreadBase::Detach(Platform
 
 // static
 bool PlatformThreadBase::CanChangeThreadType(ThreadType from, ThreadType to) {
+#if BUILDFLAG(IS_BSD)
+  return false;
+#else
   if (from >= to) {
     // Decreasing thread priority on POSIX is always allowed.
     return true;
@@ -373,10 +391,15 @@ bool PlatformThreadBase::CanChangeThread
   }
 
   return internal::CanLowerNiceTo(internal::ThreadTypeToNiceValue(to));
+#endif
 }
 
 // static
 ThreadType PlatformThreadBase::GetCurrentEffectiveThreadTypeForTest() {
+#if BUILDFLAG(IS_BSD)
+  NOTIMPLEMENTED();
+  return ThreadType::kDefault;
+#else
   // Mirrors SetCurrentThreadPriority()'s implementation.
   auto platform_specific_priority =
       internal::GetCurrentEffectiveThreadTypeForPlatformForTest();  // IN-TEST
@@ -387,6 +410,7 @@ ThreadType PlatformThreadBase::GetCurren
   int nice_value = internal::GetCurrentThreadNiceValue();
 
   return internal::NiceValueToThreadTypeForTest(nice_value);  // IN-TEST
+#endif
 }
 
 #endif  // !BUILDFLAG(IS_APPLE) && !BUILDFLAG(IS_FUCHSIA)
