$NetBSD: patch-net_disk__cache_simple_simple__file__tracker.cc,v 1.11 2025/12/11 09:13:40 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- net/disk_cache/simple/simple_file_tracker.cc.orig	2025-11-19 21:40:05.000000000 +0000
+++ net/disk_cache/simple/simple_file_tracker.cc
@@ -36,7 +36,17 @@ bool SimpleFileTracker::TrackedFiles::In
 }
 
 SimpleFileTracker::SimpleFileTracker(int file_limit)
+#if defined(OS_OPENBSD)
+{
+  // cap the file descriptor limit at 75% of the size of the
+  // file descriptor table and also substract the amount of
+  // currently used file descriptors as this should give us
+  // enough reserve to avoid hitting the limit 
+  file_limit_ = (getdtablesize() * 0.75) -  getdtablecount();
+}
+#else
     : file_limit_(file_limit) {}
+#endif
 
 SimpleFileTracker::~SimpleFileTracker() {
   DCHECK(lru_.empty());
