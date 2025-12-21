$NetBSD: patch-src_3rdparty_chromium_content_browser_file__system__access_file__path__watcher_file__path__watcher__kqueue.h,v 1.1 2025/12/21 09:38:26 markd Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/content/browser/file_system_access/file_path_watcher/file_path_watcher_kqueue.h.orig	2025-09-25 11:10:42.000000000 +0000
+++ src/3rdparty/chromium/content/browser/file_system_access/file_path_watcher/file_path_watcher_kqueue.h
@@ -5,6 +5,7 @@
 #ifndef CONTENT_BROWSER_FILE_SYSTEM_ACCESS_FILE_PATH_WATCHER_FILE_PATH_WATCHER_KQUEUE_H_
 #define CONTENT_BROWSER_FILE_SYSTEM_ACCESS_FILE_PATH_WATCHER_FILE_PATH_WATCHER_KQUEUE_H_
 
+#include <sys/time.h>
 #include <sys/event.h>
 
 #include <memory>
