$NetBSD: patch-content_browser_file__system__access_file__path__watcher_file__path__watcher__bsd.cc,v 1.14 2026/01/19 16:14:14 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- content/browser/file_system_access/file_path_watcher/file_path_watcher_bsd.cc.orig	2026-01-19 14:53:54.651598393 +0000
+++ content/browser/file_system_access/file_path_watcher/file_path_watcher_bsd.cc
@@ -0,0 +1,60 @@
+// Copyright 2024 The Chromium Authors
+// Use of this source code is governed by a BSD-style license that can be
+// found in the LICENSE file.
+
+#include "content/browser/file_system_access/file_path_watcher/file_path_watcher.h"
+
+#include <memory>
+
+#include "base/memory/ptr_util.h"
+#include "build/build_config.h"
+#include "content/browser/file_system_access/file_path_watcher/file_path_watcher_kqueue.h"
+
+namespace content {
+
+namespace {
+
+class FilePathWatcherImpl : public FilePathWatcher::PlatformDelegate {
+ public:
+  FilePathWatcherImpl() = default;
+  FilePathWatcherImpl(const FilePathWatcherImpl&) = delete;
+  FilePathWatcherImpl& operator=(const FilePathWatcherImpl&) = delete;
+  ~FilePathWatcherImpl() override = default;
+
+  bool Watch(const base::FilePath& path,
+             Type type,
+             const FilePathWatcher::Callback& callback) override {
+    DCHECK(!impl_.get());
+    if (type == Type::kRecursive) {
+      if (!FilePathWatcher::RecursiveWatchAvailable()) {
+        return false;
+      }
+    } else {
+      impl_ = std::make_unique<FilePathWatcherKQueue>();
+    }
+    DCHECK(impl_.get());
+    return impl_->Watch(path, type, callback);
+  }
+
+  void Cancel() override {
+    if (impl_.get()) {
+      impl_->Cancel();
+    }
+    set_cancelled();
+  }
+
+ private:
+  std::unique_ptr<PlatformDelegate> impl_;
+};
+
+}  // namespace
+
+FilePathWatcher::FilePathWatcher()
+    : FilePathWatcher(std::make_unique<FilePathWatcherImpl>()) {}
+
+// static
+size_t FilePathWatcher::GetQuotaLimitImpl() {
+  return std::numeric_limits<size_t>::max();
+}
+
+}  // namespace content
