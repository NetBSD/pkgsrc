$NetBSD: patch-src_3rdparty_chromium_components_storage__monitor_storage__monitor__netbsd.h,v 1.1 2021/08/03 21:04:35 markd Exp $

--- src/3rdparty/chromium/components/storage_monitor/storage_monitor_netbsd.h.orig	2020-07-12 14:12:09.343916180 +0000
+++ src/3rdparty/chromium/components/storage_monitor/storage_monitor_netbsd.h
@@ -0,0 +1,45 @@
+// Copyright 2014 The Chromium Authors. All rights reserved.
+// Use of this source code is governed by a BSD-style license that can be
+// found in the LICENSE file.
+
+// StorageMonitorNetBSD processes mount point change events, notifies listeners
+// about the addition and deletion of media devices, and answers queries about
+// mounted devices.
+// StorageMonitorNetBSD lives on the UI thread, and uses ???
+// the FILE thread to get mount point change events.
+
+#ifndef COMPONENTS_STORAGE_MONITOR_STORAGE_MONITOR_NETBSD_H_
+#define COMPONENTS_STORAGE_MONITOR_STORAGE_MONITOR_NETBSD_H_
+
+#include <map>
+#include <string>
+
+#include "base/compiler_specific.h"
+#include "base/files/file_path.h"
+#include "base/files/file_path_watcher.h"
+#include "base/memory/weak_ptr.h"
+#include "components/storage_monitor/storage_monitor.h"
+#include "content/public/browser/browser_thread.h"
+
+namespace storage_monitor {
+
+class StorageMonitorNetBSD : public StorageMonitor {
+ public:
+  // Should only be called by browser start up code.
+  // Use StorageMonitor::GetInstance() instead.
+  explicit StorageMonitorNetBSD();
+  virtual ~StorageMonitorNetBSD();
+
+  // Must be called for StorageMonitorNetBSD to work.
+  virtual void Init() override;
+ private:
+  // StorageMonitor implementation.
+  virtual bool GetStorageInfoForPath(const base::FilePath& path,
+                                     StorageInfo* device_info) const override;
+
+  DISALLOW_COPY_AND_ASSIGN(StorageMonitorNetBSD);
+};
+
+} // namespace storage_monitor
+
+#endif  // COMPONENTS_STORAGE_MONITOR_STORAGE_MONITOR_FREEBSD_H_
