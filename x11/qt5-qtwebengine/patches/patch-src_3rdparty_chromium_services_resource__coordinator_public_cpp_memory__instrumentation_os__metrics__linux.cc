$NetBSD: patch-src_3rdparty_chromium_services_resource__coordinator_public_cpp_memory__instrumentation_os__metrics__linux.cc,v 1.1 2021/08/03 21:04:35 markd Exp $

--- src/3rdparty/chromium/services/resource_coordinator/public/cpp/memory_instrumentation/os_metrics_linux.cc.orig	2020-07-15 18:56:01.000000000 +0000
+++ src/3rdparty/chromium/services/resource_coordinator/public/cpp/memory_instrumentation/os_metrics_linux.cc
@@ -23,8 +23,10 @@
 #include "build/build_config.h"
 #include "services/resource_coordinator/public/cpp/memory_instrumentation/os_metrics.h"
 
+#if !defined(OS_BSD)
 // Symbol with virtual address of the start of ELF header of the current binary.
 extern char __ehdr_start;
+#endif
 
 namespace memory_instrumentation {
 
@@ -36,6 +38,7 @@ using mojom::VmRegionPtr;
 const char kClearPeakRssCommand[] = "5";
 const uint32_t kMaxLineSize = 4096;
 
+#if !defined(OS_BSD)
 // TODO(chiniforooshan): Many of the utility functions in this anonymous
 // namespace should move to base/process/process_metrics_linux.cc to make the
 // code a lot cleaner.  However, we should do so after we made sure the metrics
@@ -227,6 +230,7 @@ uint32_t ReadLinuxProcSmapsFile(FILE* sm
   }
   return num_valid_regions;
 }
+#endif
 
 }  // namespace
 
@@ -240,6 +244,9 @@ void OSMetrics::SetProcSmapsForTesting(F
 // static
 bool OSMetrics::FillOSMemoryDump(base::ProcessId pid,
                                  mojom::RawOSMemDump* dump) {
+#if defined(OS_BSD)
+  return false;
+#else
   // TODO(chiniforooshan): There is no need to read both /statm and /status
   // files. Refactor to get everything from /status using ProcessMetric.
   auto statm_file = GetProcPidDir(pid).Append("statm");
@@ -296,10 +303,15 @@ bool OSMetrics::FillOSMemoryDump(base::P
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
@@ -317,8 +329,10 @@ std::vector<VmRegionPtr> OSMetrics::GetP
     return std::vector<VmRegionPtr>();
 
   return maps;
+#endif
 }
 
+#if !defined(OS_BSD)
 // static
 OSMetrics::MappedAndResidentPagesDumpState OSMetrics::GetMappedAndResidentPages(
     const size_t start_address,
@@ -400,5 +414,6 @@ size_t OSMetrics::GetPeakResidentSetSize
   }
   return 0;
 }
+#endif
 
 }  // namespace memory_instrumentation
