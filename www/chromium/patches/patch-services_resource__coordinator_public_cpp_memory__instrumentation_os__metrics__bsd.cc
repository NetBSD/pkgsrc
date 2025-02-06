$NetBSD: patch-services_resource__coordinator_public_cpp_memory__instrumentation_os__metrics__bsd.cc,v 1.1 2025/02/06 09:58:21 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- services/resource_coordinator/public/cpp/memory_instrumentation/os_metrics_bsd.cc.orig	2024-12-21 10:25:10.608586521 +0000
+++ services/resource_coordinator/public/cpp/memory_instrumentation/os_metrics_bsd.cc
@@ -0,0 +1,66 @@
+// Copyright 2022 The Chromium Authors. All rights reserved.
+// Use of this source code is governed by a BSD-style license that can be
+// found in the LICENSE file.
+
+#include "services/resource_coordinator/public/cpp/memory_instrumentation/os_metrics.h"
+
+#include "base/memory/page_size.h"
+#include "base/process/process.h"
+#include "base/process/process_handle.h"
+
+#include <sys/sysctl.h>
+
+#include <vector>
+
+#if BUILDFLAG(IS_OPENBSD) || BUILDFLAG(IS_NETBSD)
+#define vm_rssize info.p_vm_rssize
+#elif BUILDFLAG(IS_FREEBSD)
+#include <sys/user.h>
+#define vm_rssize info.ki_rssize
+#endif
+
+namespace memory_instrumentation {
+
+// static
+bool OSMetrics::FillOSMemoryDump(base::ProcessId pid,
+                                 mojom::RawOSMemDump* dump) {
+  base::Process process = pid == base::kNullProcessId
+                              ? base::Process::Current()
+                              : base::Process::Open(pid);
+  const size_t kPageSize = base::GetPageSize();
+#if BUILDFLAG(IS_NETBSD)
+  struct kinfo_proc2 info;
+  size_t length = sizeof(struct kinfo_proc2);
+#else
+  struct kinfo_proc info;
+  size_t length = sizeof(struct kinfo_proc);
+#endif
+#if BUILDFLAG(IS_OPENBSD)
+  int mib[] = { CTL_KERN, KERN_PROC, KERN_PROC_PID, process.Handle(),
+                static_cast<int>(length), 1 };
+#elif BUILDFLAG(IS_FREEBSD)
+  int mib[] = { CTL_KERN, KERN_PROC, KERN_PROC_PID, process.Handle() };
+#elif BUILDFLAG(IS_NETBSD)
+  int mib[] = { CTL_KERN, KERN_PROC2, KERN_PROC_PID, process.Handle(),
+                sizeof(struct kinfo_proc2), 1 };
+#endif
+
+  if (sysctl(mib, std::size(mib), &info, &length, NULL, 0) < 0)
+    return false;
+
+  dump->resident_set_kb = (vm_rssize * kPageSize) / 1024;
+  dump->platform_private_footprint->rss_anon_bytes =
+      vm_rssize * kPageSize;
+  dump->platform_private_footprint->vm_swap_bytes = 0;
+
+  return true;
+}
+
+// static
+std::vector<mojom::VmRegionPtr> OSMetrics::GetProcessMemoryMaps(
+    base::ProcessId) {
+  NOTIMPLEMENTED();
+  return std::vector<mojom::VmRegionPtr>();
+}
+
+}  // namespace memory_instrumentation
