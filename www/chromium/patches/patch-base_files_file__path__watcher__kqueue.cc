$NetBSD: patch-base_files_file__path__watcher__kqueue.cc,v 1.4 2026/08/09 06:31:06 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- base/files/file_path_watcher_kqueue.cc.orig	2026-08-05 20:17:42.000000000 +0000
+++ base/files/file_path_watcher_kqueue.cc
@@ -239,9 +239,14 @@ bool FilePathWatcherKQueue::UpdateWatche
 
     EventVector updates(valid);
     ScopedBlockingCall scoped_blocking_call(FROM_HERE, BlockingType::MAY_BLOCK);
+#if BUILDFLAG(IS_NETBSD)
+    int count = HANDLE_EINTR(
+        kevent(kqueue_, &events_[0], valid, &updates[0], valid, NULL));
+#else
     const int valid_int = checked_cast<int>(valid);
     int count = HANDLE_EINTR(
         kevent(kqueue_, &events_[0], valid_int, &updates[0], valid_int, NULL));
+#endif
     if (!AreKeventValuesValid(&updates[0], count)) {
       return false;
     }
@@ -294,9 +299,14 @@ bool FilePathWatcherKQueue::Watch(const 
   EventVector responses(last_entry);
 
   ScopedBlockingCall scoped_blocking_call(FROM_HERE, BlockingType::MAY_BLOCK);
+#if BUILDFLAG(IS_NETBSD)
+  int count = HANDLE_EINTR(kevent(kqueue_, &events_[0], last_entry,
+                                  &responses[0], last_entry, NULL));
+#else
   const int last_entry_int = checked_cast<int>(last_entry);
   int count = HANDLE_EINTR(kevent(kqueue_, &events_[0], last_entry_int,
                                   &responses[0], last_entry_int, NULL));
+#endif
   if (!AreKeventValuesValid(&responses[0], count)) {
     // Calling Cancel() here to close any file descriptors that were opened.
     // This would happen in the destructor anyways, but FilePathWatchers tend to
@@ -345,9 +355,13 @@ void FilePathWatcherKQueue::OnKQueueRead
   // occurred.
   EventVector updates(events_.size());
   struct timespec timeout = {0, 0};
+#if BUILDFLAG(IS_NETBSD)
+  int count = HANDLE_EINTR(kevent(kqueue_, NULL, 0, &updates[0],
+                                  updates.size(), &timeout));
+#else
   int count = HANDLE_EINTR(kevent(kqueue_, NULL, 0, &updates[0],
                                   checked_cast<int>(updates.size()), &timeout));
-
+#endif
   // Error values are stored within updates, so check to make sure that no
   // errors occurred.
   if (!AreKeventValuesValid(&updates[0], count)) {
