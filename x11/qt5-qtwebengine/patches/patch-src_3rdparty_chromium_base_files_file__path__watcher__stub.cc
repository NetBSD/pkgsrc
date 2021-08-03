$NetBSD: patch-src_3rdparty_chromium_base_files_file__path__watcher__stub.cc,v 1.1 2021/08/03 21:04:34 markd Exp $

--- src/3rdparty/chromium/base/files/file_path_watcher_stub.cc.orig	2020-06-25 09:31:18.000000000 +0000
+++ src/3rdparty/chromium/base/files/file_path_watcher_stub.cc
@@ -5,10 +5,13 @@
 // This file exists for Unix systems which don't have the inotify headers, and
 // thus cannot build file_watcher_inotify.cc
 
+#include <memory>
 #include "base/files/file_path_watcher.h"
+#include "base/files/file_path_watcher_kqueue.h"
 
 #include "base/macros.h"
 #include "base/memory/ptr_util.h"
+#include "build/build_config.h"
 
 namespace base {
 
@@ -22,12 +25,29 @@ class FilePathWatcherImpl : public FileP
   bool Watch(const FilePath& path,
              bool recursive,
              const FilePathWatcher::Callback& callback) override {
+#if defined(OS_BSD)
+    DCHECK(!impl_.get());
+    if (recursive) {
+      return false;
+    } else {
+      impl_ = std::make_unique<FilePathWatcherKQueue>();
+    }
+    DCHECK(impl_.get());
+    return impl_->Watch(path, recursive, callback);
+#else
     return false;
+#endif
   }
 
-  void Cancel() override {}
+  void Cancel() override {
+    if (impl_.get())
+      impl_->Cancel();
+    set_cancelled();
+  }
 
  private:
+  std::unique_ptr<PlatformDelegate> impl_;
+
   DISALLOW_COPY_AND_ASSIGN(FilePathWatcherImpl);
 };
 
