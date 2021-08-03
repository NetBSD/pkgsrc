$NetBSD: patch-src_3rdparty_chromium_base_process_process__handle__netbsd.cc,v 1.1 2021/08/03 21:04:34 markd Exp $

--- src/3rdparty/chromium/base/process/process_handle_netbsd.cc.orig	2020-07-09 13:18:47.299833505 +0000
+++ src/3rdparty/chromium/base/process/process_handle_netbsd.cc
@@ -0,0 +1,52 @@
+// Copyright (c) 2011 The Chromium Authors. All rights reserved.
+// Use of this source code is governed by a BSD-style license that can be
+// found in the LICENSE file.
+
+#include "base/process/process_handle.h"
+#include "base/stl_util.h"
+
+#include <stddef.h>
+#include <sys/sysctl.h>
+#include <sys/types.h>
+#include <unistd.h>
+#include <cstring>
+
+namespace base {
+
+ProcessId GetParentProcessId(ProcessHandle process) {
+  struct kinfo_proc2 info;
+  size_t length;
+  int mib[] = { CTL_KERN, KERN_PROC2, KERN_PROC_PID, process,
+                sizeof(struct kinfo_proc2), 1 };
+
+  if (sysctl(mib, base::size(mib), NULL, &length, NULL, 0) < 0)
+    return -1;
+
+  mib[5] = (length / sizeof(struct kinfo_proc2));
+
+  if (sysctl(mib, base::size(mib), &info, &length, NULL, 0) < 0)
+    return -1;
+
+  return info.p_ppid;
+}
+
+FilePath GetProcessExecutablePath(ProcessHandle process) {
+  struct kinfo_proc2 kp;
+  size_t len;
+  int mib[] = { CTL_KERN, KERN_PROC2, KERN_PROC_PID, process,
+                sizeof(struct kinfo_proc2), 1 };
+
+  if (sysctl(mib, base::size(mib), NULL, &len, NULL, 0) == -1)
+    return FilePath();
+  mib[5] = (len / sizeof(struct kinfo_proc2));
+  if (sysctl(mib, base::size(mib), &kp, &len, NULL, 0) < 0)
+    return FilePath();
+  if ((kp.p_flag & P_SYSTEM) != 0)
+    return FilePath();
+  if (strcmp(kp.p_comm, "chrome") == 0)
+    return FilePath(kp.p_comm);
+
+  return FilePath();
+}
+
+}  // namespace base
