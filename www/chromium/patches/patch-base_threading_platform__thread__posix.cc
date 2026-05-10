$NetBSD: patch-base_threading_platform__thread__posix.cc,v 1.19 2026/05/10 15:29:48 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- base/threading/platform_thread_posix.cc.orig	2026-04-28 23:05:57.000000000 +0200
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
@@ -80,6 +87,7 @@ void* ThreadFunc(void* params) {
       base::DisallowSingleton();
     }
 
+#if !BUILDFLAG(IS_BSD)
 #if PA_BUILDFLAG(USE_PARTITION_ALLOC_AS_MALLOC)
     partition_alloc::internal::StackTopRegistry::Get().NotifyThreadCreated();
 #endif
@@ -93,6 +101,7 @@ void* ThreadFunc(void* params) {
     // where they were created. This explicitly sets the priority of all new
     // threads.
     PlatformThread::SetCurrentThreadType(thread_params->thread_type);
+#endif
   }
 
   ThreadIdNameManager::GetInstance()->RegisterThread(
@@ -270,6 +279,12 @@ PlatformThreadId PlatformThreadBase::Cur
 
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
@@ -363,6 +378,9 @@ void PlatformThreadBase::Detach(Platform
 
 // static
 bool PlatformThreadBase::CanChangeThreadType(ThreadType from, ThreadType to) {
+#if BUILDFLAG(IS_BSD)
+  return false;
+#else
   if (from >= to) {
     // Decreasing thread priority on POSIX is always allowed.
     return true;
@@ -372,10 +390,15 @@ bool PlatformThreadBase::CanChangeThread
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
@@ -386,6 +409,7 @@ ThreadType PlatformThreadBase::GetCurren
   int nice_value = internal::GetCurrentThreadNiceValue();
 
   return internal::NiceValueToThreadTypeForTest(nice_value);  // IN-TEST
+#endif
 }
 
 #endif  // !BUILDFLAG(IS_APPLE) && !BUILDFLAG(IS_FUCHSIA)
