$NetBSD: patch-src_3rdparty_chromium_net_disk__cache_simple_simple__file__tracker.cc,v 1.1 2025/12/21 09:38:34 markd Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/net/disk_cache/simple/simple_file_tracker.cc.orig	2025-10-02 00:36:39.000000000 +0000
+++ src/3rdparty/chromium/net/disk_cache/simple/simple_file_tracker.cc
@@ -37,7 +37,17 @@ bool SimpleFileTracker::TrackedFiles::In
 }
 
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
