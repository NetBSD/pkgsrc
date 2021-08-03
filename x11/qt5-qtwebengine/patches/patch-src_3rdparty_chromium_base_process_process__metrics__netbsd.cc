$NetBSD: patch-src_3rdparty_chromium_base_process_process__metrics__netbsd.cc,v 1.1 2021/08/03 21:04:34 markd Exp $

--- src/3rdparty/chromium/base/process/process_metrics_netbsd.cc.orig	2021-03-13 05:56:47.620639617 +0000
+++ src/3rdparty/chromium/base/process/process_metrics_netbsd.cc
@@ -0,0 +1,82 @@
+// Copyright (c) 2013 The Chromium Authors. All rights reserved.
+// Use of this source code is governed by a BSD-style license that can be
+// found in the LICENSE file.
+
+#include "base/process/process_metrics.h"
+
+#include <stddef.h>
+#include <stdint.h>
+#include <sys/param.h>
+#include <sys/sysctl.h>
+#include <sys/vmmeter.h>
+
+#include "base/memory/ptr_util.h"
+#include "base/process/process_metrics_iocounters.h"
+#include "base/stl_util.h"
+#include "base/logging.h"
+
+namespace base {
+
+// static
+std::unique_ptr<ProcessMetrics> ProcessMetrics::CreateProcessMetrics(
+    ProcessHandle process) {
+  return WrapUnique(new ProcessMetrics(process));
+}
+
+bool ProcessMetrics::GetIOCounters(IoCounters* io_counters) const {
+  return false;
+}
+
+static int GetProcessCPU(pid_t pid) {
+  struct kinfo_proc2 info;
+  size_t length;
+  int mib[] = { CTL_KERN, KERN_PROC2, KERN_PROC_PID, pid,
+                sizeof(struct kinfo_proc2), 1 };
+
+  if (sysctl(mib, base::size(mib), NULL, &length, NULL, 0) < 0)
+    return -1;
+
+  mib[5] = (length / sizeof(struct kinfo_proc2));
+
+  if (sysctl(mib, base::size(mib), &info, &length, NULL, 0) < 0)
+    return 0;
+
+  return info.p_pctcpu;
+}
+
+TimeDelta ProcessMetrics::GetCumulativeCPUUsage() {
+  //NOTREACHED();
+  return TimeDelta();
+}
+
+#if 0
+  XXXX
+bool ProcessMetrics::GetCumulativeCPUUsagePerThread(CPUUsagePerThread&) {
+  //NOTREACHED();
+  return false;
+}
+#endif
+
+ProcessMetrics::ProcessMetrics(ProcessHandle process)
+    : process_(process) {}
+
+size_t GetSystemCommitCharge() {
+  int mib[] = { CTL_VM, VM_METER };
+  int pagesize;
+  struct vmtotal vmtotal;
+  unsigned long mem_total, mem_free, mem_inactive;
+  size_t len = sizeof(vmtotal);
+
+  if (sysctl(mib, base::size(mib), &vmtotal, &len, NULL, 0) < 0)
+    return 0;
+
+  mem_total = vmtotal.t_vm;
+  mem_free = vmtotal.t_free;
+  mem_inactive = vmtotal.t_vm - vmtotal.t_avm;
+
+  pagesize = getpagesize();
+
+  return mem_total - (mem_free*pagesize) - (mem_inactive*pagesize);
+}
+
+}  // namespace base
