$NetBSD: patch-base_threading_platform__thread__posix.cc,v 1.1 2025/02/06 09:57:43 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- base/threading/platform_thread_posix.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ base/threading/platform_thread_posix.cc
@@ -77,11 +77,11 @@ void* ThreadFunc(void* params) {
     if (!thread_params->joinable)
       base::DisallowSingleton();
 
-#if PA_BUILDFLAG(USE_PARTITION_ALLOC_AS_MALLOC)
+#if PA_BUILDFLAG(USE_PARTITION_ALLOC_AS_MALLOC) && !BUILDFLAG(IS_BSD)
     partition_alloc::internal::StackTopRegistry::Get().NotifyThreadCreated();
 #endif
 
-#if !BUILDFLAG(IS_NACL)
+#if !BUILDFLAG(IS_NACL) && !BUILDFLAG(IS_BSD)
 #if BUILDFLAG(IS_APPLE)
     PlatformThread::SetCurrentThreadRealtimePeriodValue(
         delegate->GetRealtimePeriod());
@@ -265,6 +265,8 @@ PlatformThreadId PlatformThreadBase::Cur
   return reinterpret_cast<int32_t>(pthread_self());
 #elif BUILDFLAG(IS_POSIX) && BUILDFLAG(IS_AIX)
   return pthread_self();
+#elif BUILDFLAG(IS_BSD)
+  return reinterpret_cast<uint64_t>(pthread_self());
 #elif BUILDFLAG(IS_POSIX) && !BUILDFLAG(IS_AIX)
   return reinterpret_cast<int64_t>(pthread_self());
 #endif
@@ -355,7 +357,7 @@ void PlatformThreadBase::Detach(Platform
 
 // static
 bool PlatformThreadBase::CanChangeThreadType(ThreadType from, ThreadType to) {
-#if BUILDFLAG(IS_NACL)
+#if BUILDFLAG(IS_NACL) || BUILDFLAG(IS_BSD)
   return false;
 #else
   if (from >= to) {
@@ -376,6 +378,9 @@ void SetCurrentThreadTypeImpl(ThreadType
                               MessagePumpType pump_type_hint) {
 #if BUILDFLAG(IS_NACL)
   NOTIMPLEMENTED();
+// avoid pledge(2) violation
+#elif BUILDFLAG(IS_BSD)
+   NOTIMPLEMENTED();
 #else
   if (internal::SetCurrentThreadTypeForPlatform(thread_type, pump_type_hint))
     return;
@@ -398,7 +403,7 @@ void SetCurrentThreadTypeImpl(ThreadType
 
 // static
 ThreadPriorityForTest PlatformThreadBase::GetCurrentThreadPriorityForTest() {
-#if BUILDFLAG(IS_NACL)
+#if BUILDFLAG(IS_NACL) || BUILDFLAG(IS_BSD)
   NOTIMPLEMENTED();
   return ThreadPriorityForTest::kNormal;
 #else
