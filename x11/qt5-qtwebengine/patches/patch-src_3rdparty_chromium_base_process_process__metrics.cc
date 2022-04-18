$NetBSD: patch-src_3rdparty_chromium_base_process_process__metrics.cc,v 1.2 2022/04/18 11:18:18 adam Exp $

--- src/3rdparty/chromium/base/process/process_metrics.cc.orig	2021-02-19 16:41:59.000000000 +0000
+++ src/3rdparty/chromium/base/process/process_metrics.cc
@@ -49,7 +49,7 @@ SystemMetrics SystemMetrics::Sample() {
   SystemMetrics system_metrics;
 
   system_metrics.committed_memory_ = GetSystemCommitCharge();
-#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID) || defined(OS_BSD)
   GetSystemMemoryInfo(&system_metrics.memory_info_);
   GetVmStatInfo(&system_metrics.vmstat_info_);
   GetSystemDiskInfo(&system_metrics.disk_info_);
@@ -68,7 +68,7 @@ std::unique_ptr<Value> SystemMetrics::To
   std::unique_ptr<DictionaryValue> res(new DictionaryValue());
 
   res->SetIntKey("committed_memory", static_cast<int>(committed_memory_));
-#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID) || defined(OS_BSD)
   std::unique_ptr<DictionaryValue> meminfo = memory_info_.ToValue();
   std::unique_ptr<DictionaryValue> vmstat = vmstat_info_.ToValue();
   meminfo->MergeDictionary(vmstat.get());
