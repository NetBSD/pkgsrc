$NetBSD: patch-base_process_process__metrics__netbsd.cc,v 1.1 2025/02/06 09:57:41 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- base/process/process_metrics_netbsd.cc.orig	2024-12-21 10:25:09.621647360 +0000
+++ base/process/process_metrics_netbsd.cc
@@ -0,0 +1,175 @@
+// Copyright 2013 The Chromium Authors
+// Use of this source code is governed by a BSD-style license that can be
+// found in the LICENSE file.
+
+#include "base/process/process_metrics.h"
+
+#include <stddef.h>
+#include <stdint.h>
+#include <fcntl.h>
+#include <sys/param.h>
+#include <sys/sysctl.h>
+#include <sys/vmmeter.h>
+
+#include "base/memory/ptr_util.h"
+#include "base/types/expected.h"
+#include "base/values.h"
+#include "base/notreached.h"
+
+namespace base {
+
+ProcessMetrics::ProcessMetrics(ProcessHandle process) : process_(process) {}
+
+base::expected<TimeDelta, ProcessCPUUsageError>
+ProcessMetrics::GetCumulativeCPUUsage() {
+  struct kinfo_proc2 info;
+  size_t length = sizeof(struct kinfo_proc2);
+  struct timeval tv;
+
+  int mib[] = { CTL_KERN, KERN_PROC2, KERN_PROC_PID, process_,
+                sizeof(struct kinfo_proc2), 1 };
+
+  if (sysctl(mib, std::size(mib), &info, &length, NULL, 0) < 0) {
+    return base::unexpected(ProcessCPUUsageError::kSystemError);
+  }
+
+  tv.tv_sec = info.p_rtime_sec;
+  tv.tv_usec = info.p_rtime_usec;
+
+  return base::ok(Microseconds(TimeValToMicroseconds(tv)));
+}
+
+// static
+std::unique_ptr<ProcessMetrics> ProcessMetrics::CreateProcessMetrics(
+    ProcessHandle process) {
+  return WrapUnique(new ProcessMetrics(process));
+}
+
+size_t GetSystemCommitCharge() {
+  int mib[] = { CTL_VM, VM_METER };
+  size_t pagesize;
+  struct vmtotal vmtotal;
+  unsigned long mem_total, mem_free, mem_inactive;
+  size_t len = sizeof(vmtotal);
+
+  if (sysctl(mib, std::size(mib), &vmtotal, &len, NULL, 0) < 0) {
+    return 0;
+  }
+
+  mem_total = vmtotal.t_vm;
+  mem_free = vmtotal.t_free;
+  mem_inactive = vmtotal.t_vm - vmtotal.t_avm;
+
+  pagesize = checked_cast<size_t>(getpagesize());
+
+  return mem_total - (mem_free*pagesize) - (mem_inactive*pagesize);
+}
+
+int ProcessMetrics::GetOpenFdCount() const {
+  return -1;
+}
+
+int ProcessMetrics::GetOpenFdSoftLimit() const {
+  return getdtablesize();
+//  return GetMaxFds();
+}
+
+uint64_t ProcessMetrics::GetVmSwapBytes() const {
+  NOTIMPLEMENTED();
+  return 0;
+}
+
+bool GetSystemMemoryInfo(SystemMemoryInfoKB* meminfo) {
+  NOTIMPLEMENTED_LOG_ONCE();
+  return false;
+}
+
+bool GetSystemDiskInfo(SystemDiskInfo* diskinfo) {
+  NOTIMPLEMENTED();
+  return false;
+}
+
+bool GetVmStatInfo(VmStatInfo* vmstat) {
+  NOTIMPLEMENTED();
+  return false;
+}
+
+int ProcessMetrics::GetIdleWakeupsPerSecond() {
+  NOTIMPLEMENTED();
+  return 0;
+}
+
+Value::Dict SystemMemoryInfoKB::ToDict() const {
+  Value::Dict res;
+  res.Set("total", total);
+  res.Set("free", free);
+  res.Set("available", available);
+  res.Set("buffers", buffers);
+  res.Set("cached", cached);
+  res.Set("active_anon", active_anon);
+  res.Set("inactive_anon", inactive_anon);
+  res.Set("active_file", active_file);
+  res.Set("inactive_file", inactive_file);
+  res.Set("swap_total", swap_total);
+  res.Set("swap_free", swap_free);
+  res.Set("swap_used", swap_total - swap_free);
+  res.Set("dirty", dirty);
+  res.Set("reclaimable", reclaimable);
+
+  NOTIMPLEMENTED();
+
+  return res;
+}
+
+Value::Dict VmStatInfo::ToDict() const {
+  Value::Dict res;
+  res.Set("pswpin", static_cast<int>(pswpin));
+  res.Set("pswpout", static_cast<int>(pswpout));
+  res.Set("pgmajfault", static_cast<int>(pgmajfault));
+
+  NOTIMPLEMENTED();
+
+  return res;
+}
+
+SystemDiskInfo::SystemDiskInfo() {
+  reads = 0;
+  reads_merged = 0;
+  sectors_read = 0;
+  read_time = 0;
+  writes = 0;
+  writes_merged = 0;
+  sectors_written = 0;
+  write_time = 0;
+  io = 0;
+  io_time = 0;
+  weighted_io_time = 0;
+}
+
+SystemDiskInfo::SystemDiskInfo(const SystemDiskInfo&) = default;
+
+SystemDiskInfo& SystemDiskInfo::operator=(const SystemDiskInfo&) = default;
+
+Value::Dict SystemDiskInfo::ToDict() const {
+  Value::Dict res;
+
+  // Write out uint64_t variables as doubles.
+  // Note: this may discard some precision, but for JS there's no other option.
+  res.Set("reads", static_cast<double>(reads));
+  res.Set("reads_merged", static_cast<double>(reads_merged));
+  res.Set("sectors_read", static_cast<double>(sectors_read));
+  res.Set("read_time", static_cast<double>(read_time));
+  res.Set("writes", static_cast<double>(writes));
+  res.Set("writes_merged", static_cast<double>(writes_merged));
+  res.Set("sectors_written", static_cast<double>(sectors_written));
+  res.Set("write_time", static_cast<double>(write_time));
+  res.Set("io", static_cast<double>(io));
+  res.Set("io_time", static_cast<double>(io_time));
+  res.Set("weighted_io_time", static_cast<double>(weighted_io_time));
+
+  NOTIMPLEMENTED();
+
+  return res;
+}
+
+}  // namespace base
