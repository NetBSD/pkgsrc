$NetBSD: patch-base_process_process__handle__netbsd.cc,v 1.1 2025/02/06 09:57:41 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- base/process/process_handle_netbsd.cc.orig	2024-12-21 10:25:09.614530232 +0000
+++ base/process/process_handle_netbsd.cc
@@ -0,0 +1,55 @@
+// Copyright 2011 The Chromium Authors
+// Use of this source code is governed by a BSD-style license that can be
+// found in the LICENSE file.
+
+#include "base/process/process_handle.h"
+#include "base/files/file_util.h"
+
+#include <stddef.h>
+#include <sys/param.h>
+#include <sys/proc.h>
+#include <sys/sysctl.h>
+#include <sys/types.h>
+#include <unistd.h>
+
+#include <optional>
+
+#include "base/files/file_path.h"
+#include "base/posix/sysctl.h"
+
+namespace base {
+
+ProcessId GetParentProcessId(ProcessHandle process) {
+  struct kinfo_proc2 *info;
+  size_t length;
+  pid_t ppid;
+  int mib[] = { CTL_KERN, KERN_PROC2, KERN_PROC_PID, process,
+                sizeof(struct kinfo_proc2), 1 };
+
+  if (sysctl(mib, std::size(mib), NULL, &length, NULL, 0) < 0)
+    return -1;
+
+  info = (struct kinfo_proc2 *)malloc(length);
+
+  mib[5] = static_cast<int>((length / sizeof(struct kinfo_proc2)));
+
+  if (sysctl(mib, std::size(mib), info, &length, NULL, 0) < 0) {
+    ppid = -1;
+    goto out;
+  }
+
+  ppid = info->p_ppid;
+
+out:
+  free(info);
+  return ppid;
+}
+
+FilePath GetProcessExecutablePath(ProcessHandle process) {
+  std::optional<std::string> pathname =
+      base::StringSysctl({CTL_KERN, KERN_PROC_ARGS, process, KERN_PROC_PATHNAME});
+
+  return FilePath(pathname.value_or(std::string{}));
+}
+
+}  // namespace base
