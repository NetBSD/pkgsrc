$NetBSD: patch-base_profiler_thread__delegate__posix.cc,v 1.14 2026/01/19 16:14:06 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- base/profiler/thread_delegate_posix.cc.orig	2026-01-07 00:50:30.000000000 +0000
+++ base/profiler/thread_delegate_posix.cc
@@ -15,7 +15,7 @@
 #include "base/process/process_handle.h"
 #include "build/build_config.h"
 
-#if !(BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS))
+#if !(BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD))
 #include "base/profiler/stack_base_address_posix.h"
 #endif
 
@@ -24,7 +24,7 @@ namespace base {
 std::unique_ptr<ThreadDelegatePosix> ThreadDelegatePosix::Create(
     SamplingProfilerThreadToken thread_token) {
   std::optional<uintptr_t> base_address;
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   base_address = thread_token.stack_base_address;
 #else
   base_address =
