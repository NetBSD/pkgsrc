$NetBSD: patch-base_process_memory__linux.cc,v 1.14 2026/01/19 16:14:06 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- base/process/memory_linux.cc.orig	2026-01-07 00:50:30.000000000 +0000
+++ base/process/memory_linux.cc
@@ -29,6 +29,7 @@ void* __libc_calloc(size_t, size_t);
 
 namespace base {
 
+#if !BUILDFLAG(IS_BSD)
 namespace {
 
 void ReleaseReservationOrTerminate() {
@@ -39,12 +40,14 @@ void ReleaseReservationOrTerminate() {
 }
 
 }  // namespace
+#endif
 
 void EnableTerminationOnHeapCorruption() {
   // On Linux, there nothing to do AFAIK.
 }
 
 void EnableTerminationOnOutOfMemory() {
+#if !BUILDFLAG(IS_BSD)
   // Set the new-out of memory handler.
   std::set_new_handler(&ReleaseReservationOrTerminate);
   // If we're using glibc's allocator, the above functions will override
@@ -53,8 +56,10 @@ void EnableTerminationOnOutOfMemory() {
 #if PA_BUILDFLAG(USE_ALLOCATOR_SHIM)
   allocator_shim::SetCallNewHandlerOnMallocFailure(true);
 #endif
+#endif
 }
 
+#if !BUILDFLAG(IS_BSD)
 // ScopedAllowBlocking() has private constructor and it can only be used in
 // friend classes/functions. Declaring a class is easier in this situation to
 // avoid adding more dependency to thread_restrictions.h because of the
@@ -112,6 +117,7 @@ bool AdjustOOMScoreHelper::AdjustOOMScor
 bool AdjustOOMScore(ProcessId process, int score) {
   return AdjustOOMScoreHelper::AdjustOOMScore(process, score);
 }
+#endif
 
 bool UncheckedCalloc(size_t num_items, size_t size, void** result) {
 #if PA_BUILDFLAG(USE_ALLOCATOR_SHIM)
