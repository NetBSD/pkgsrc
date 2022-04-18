$NetBSD: patch-src_3rdparty_chromium_services_resource__coordinator_public_cpp_memory__instrumentation_os__metrics__linux.cc,v 1.2 2022/04/18 11:18:19 adam Exp $

--- src/3rdparty/chromium/services/resource_coordinator/public/cpp/memory_instrumentation/os_metrics_linux.cc.orig	2021-02-19 16:41:59.000000000 +0000
+++ src/3rdparty/chromium/services/resource_coordinator/public/cpp/memory_instrumentation/os_metrics_linux.cc
@@ -5,7 +5,6 @@
 #include <dlfcn.h>
 #include <fcntl.h>
 #include <stdint.h>
-#include <sys/prctl.h>
 
 #include <memory>
 
@@ -27,8 +26,14 @@
 #include "build/build_config.h"
 #include "services/resource_coordinator/public/cpp/memory_instrumentation/os_metrics.h"
 
+#if !defined(OS_BSD)
+#include <sys/prctl.h>
+#endif
+
+#if !defined(OS_BSD)
 // Symbol with virtual address of the start of ELF header of the current binary.
 extern char __ehdr_start;
+#endif
 
 namespace memory_instrumentation {
 
@@ -40,6 +45,7 @@ using mojom::VmRegionPtr;
 const char kClearPeakRssCommand[] = "5";
 const uint32_t kMaxLineSize = 4096;
 
+#if !defined(OS_BSD)
 // TODO(chiniforooshan): Many of the utility functions in this anonymous
 // namespace should move to base/process/process_metrics_linux.cc to make the
 // code a lot cleaner.  However, we should do so after we made sure the metrics
@@ -269,6 +275,7 @@ class ScopedProcessSetDumpable {
 
   bool was_dumpable_;
 };
+#endif
 
 }  // namespace
 
@@ -282,6 +289,9 @@ void OSMetrics::SetProcSmapsForTesting(F
 // static
 bool OSMetrics::FillOSMemoryDump(base::ProcessId pid,
                                  mojom::RawOSMemDump* dump) {
+#if defined(OS_BSD)
+  return false;
+#else
   // TODO(chiniforooshan): There is no need to read both /statm and /status
   // files. Refactor to get everything from /status using ProcessMetric.
   auto statm_file = GetProcPidDir(pid).Append("statm");
@@ -338,10 +348,15 @@ bool OSMetrics::FillOSMemoryDump(base::P
 #endif  //  defined(OS_ANDROID)
 
   return true;
+#endif
 }
 
 // static
 std::vector<VmRegionPtr> OSMetrics::GetProcessMemoryMaps(base::ProcessId pid) {
+#if defined(OS_BSD)
+  NOTIMPLEMENTED();
+  return std::vector<VmRegionPtr>();
+#else
   std::vector<VmRegionPtr> maps;
   uint32_t res = 0;
   if (g_proc_smaps_for_testing) {
@@ -359,8 +374,10 @@ std::vector<VmRegionPtr> OSMetrics::GetP
     return std::vector<VmRegionPtr>();
 
   return maps;
+#endif
 }
 
+#if !defined(OS_BSD)
 // static
 OSMetrics::MappedAndResidentPagesDumpState OSMetrics::GetMappedAndResidentPages(
     const size_t start_address,
@@ -448,5 +465,6 @@ size_t OSMetrics::GetPeakResidentSetSize
   }
   return 0;
 }
+#endif
 
 }  // namespace memory_instrumentation
