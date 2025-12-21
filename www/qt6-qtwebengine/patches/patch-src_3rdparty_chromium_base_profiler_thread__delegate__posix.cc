$NetBSD: patch-src_3rdparty_chromium_base_profiler_thread__delegate__posix.cc,v 1.1 2025/12/21 09:38:15 markd Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/base/profiler/thread_delegate_posix.cc.orig	2025-05-29 01:27:28.000000000 +0000
+++ src/3rdparty/chromium/base/profiler/thread_delegate_posix.cc
@@ -19,7 +19,7 @@
 #include "base/process/process_handle.h"
 #include "build/build_config.h"
 
-#if !(BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS))
+#if !(BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD))
 #include "base/profiler/stack_base_address_posix.h"
 #endif
 
@@ -28,7 +28,7 @@ namespace base {
 std::unique_ptr<ThreadDelegatePosix> ThreadDelegatePosix::Create(
     SamplingProfilerThreadToken thread_token) {
   std::optional<uintptr_t> base_address;
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   base_address = thread_token.stack_base_address;
 #else
   base_address =
