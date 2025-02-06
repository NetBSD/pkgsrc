$NetBSD: patch-content_browser_file__system__access_file__path__watcher_file__path__watcher__kqueue.h,v 1.1 2025/02/06 09:58:05 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- content/browser/file_system_access/file_path_watcher/file_path_watcher_kqueue.h.orig	2024-12-17 17:58:49.000000000 +0000
+++ content/browser/file_system_access/file_path_watcher/file_path_watcher_kqueue.h
@@ -5,6 +5,7 @@
 #ifndef CONTENT_BROWSER_FILE_SYSTEM_ACCESS_FILE_PATH_WATCHER_FILE_PATH_WATCHER_KQUEUE_H_
 #define CONTENT_BROWSER_FILE_SYSTEM_ACCESS_FILE_PATH_WATCHER_FILE_PATH_WATCHER_KQUEUE_H_
 
+#include <sys/time.h>
 #include <sys/event.h>
 
 #include <memory>
