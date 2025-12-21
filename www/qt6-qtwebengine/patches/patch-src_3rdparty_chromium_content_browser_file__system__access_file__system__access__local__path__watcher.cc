$NetBSD: patch-src_3rdparty_chromium_content_browser_file__system__access_file__system__access__local__path__watcher.cc,v 1.1 2025/12/21 09:38:26 markd Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/content/browser/file_system_access/file_system_access_local_path_watcher.cc.orig	2025-05-29 01:27:28.000000000 +0000
+++ src/3rdparty/chromium/content/browser/file_system_access/file_system_access_local_path_watcher.cc
@@ -63,7 +63,7 @@ void FileSystemAccessLocalPathWatcher::I
       .type = scope().IsRecursive() ? FilePathWatcher::Type::kRecursive
                                     : FilePathWatcher::Type::kNonRecursive,
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_MAC)
+    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
       // Note: `report_modified_path` is also present on Android
       // and Fuchsia. Update this switch if support for watching
       // the local file system is added on those platforms.
