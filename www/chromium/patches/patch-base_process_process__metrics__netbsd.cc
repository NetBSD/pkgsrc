$NetBSD: patch-base_process_process__metrics__netbsd.cc,v 1.6 2025/09/08 13:24:16 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- base/process/process_metrics_netbsd.cc.orig	2025-09-05 09:59:07.538330448 +0000
+++ base/process/process_metrics_netbsd.cc
@@ -0,0 +1,173 @@
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
+#include "base/files/dir_reader_posix.h" // DirReaderPosix
+#include "base/process/internal_linux.h" // GetProcPidDir()
+#include "base/memory/ptr_util.h"
+#include "base/types/expected.h"
+#include "base/values.h"
+#include "base/notimplemented.h"
+
+namespace base {
+
+ProcessMetrics::ProcessMetrics(ProcessHandle process) : process_(process) {}
+
+base::expected<ProcessMemoryInfo, ProcessUsageError>
+ProcessMetrics::GetMemoryInfo() const {
+  ProcessMemoryInfo memory_info;
+  struct kinfo_proc2 info;
+  size_t length = sizeof(struct kinfo_proc2);
+
+  int mib[] = { CTL_KERN, KERN_PROC2, KERN_PROC_PID, process_,
+                sizeof(struct kinfo_proc2), 1 };
+
+  if (process_ == 0) {
+    return base::unexpected(ProcessUsageError::kSystemError);
+  }
+
+  if (sysctl(mib, std::size(mib), &info, &length, NULL, 0) < 0) {
+    return base::unexpected(ProcessUsageError::kSystemError);
+  }
+
+  if (length == 0) {
+    return base::unexpected(ProcessUsageError::kProcessNotFound);
+  }
+
+  memory_info.resident_set_bytes =
+    checked_cast<uint64_t>(info.p_vm_rssize * getpagesize());
+
+  return memory_info;
+}
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
+  if (process_ == 0) {
+    return base::unexpected(ProcessCPUUsageError::kSystemError);
+  }
+
+  if (sysctl(mib, std::size(mib), &info, &length, NULL, 0) < 0) {
+    return base::unexpected(ProcessCPUUsageError::kSystemError);
+  }
+
+  if (length == 0) {
+    return base::unexpected(ProcessCPUUsageError::kProcessNotFound);
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
+  return mem_total - (mem_free * pagesize) - (mem_inactive * pagesize);
+}
+
+int ProcessMetrics::GetOpenFdCount() const {
+  // Use /proc/<pid>/fd to count the number of entries there.
+  FilePath fd_path = internal::GetProcPidDir(process_).Append("fd");
+
+  DirReaderPosix dir_reader(fd_path.value().c_str());
+  if (!dir_reader.IsValid()) {
+    return -1;
+  }
+
+  int total_count = 0;
+  for (; dir_reader.Next();) {
+    const char* name = dir_reader.name();
+    if (strcmp(name, ".") != 0 && strcmp(name, "..") != 0) {
+      ++total_count;
+    }
+  }
+
+  return total_count;
+}
+
+int ProcessMetrics::GetOpenFdSoftLimit() const {
+  return getdtablesize();
+//  return GetMaxFds();
+}
+
+bool ProcessMetrics::GetPageFaultCounts(PageFaultCounts* counts) const {
+  NOTIMPLEMENTED();
+  return false;
+}
+
+bool GetSystemMemoryInfo(SystemMemoryInfoKB* meminfo) {
+  NOTIMPLEMENTED();
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
+}  // namespace base
