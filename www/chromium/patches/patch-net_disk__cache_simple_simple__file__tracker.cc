$NetBSD: patch-net_disk__cache_simple_simple__file__tracker.cc,v 1.1 2025/02/06 09:58:15 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- net/disk_cache/simple/simple_file_tracker.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ net/disk_cache/simple/simple_file_tracker.cc
@@ -35,7 +35,17 @@ void RecordFileDescripterLimiterOp(FileD
 }  // namespace
 
 SimpleFileTracker::SimpleFileTracker(int file_limit)
+#if defined(OS_OPENBSD)
+{
+  // cap the file descriptor limit at 85% of the size of the
+  // file descriptor table and also substract the amount of
+  // currently used file descriptors as this should give us
+  // enough reserve to avoid hitting the limit 
+  file_limit_ = (getdtablesize() * 0.85) -  getdtablecount();
+}
+#else
     : file_limit_(file_limit) {}
+#endif
 
 SimpleFileTracker::~SimpleFileTracker() {
   DCHECK(lru_.empty());
