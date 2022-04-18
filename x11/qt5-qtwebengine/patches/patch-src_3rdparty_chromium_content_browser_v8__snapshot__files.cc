$NetBSD: patch-src_3rdparty_chromium_content_browser_v8__snapshot__files.cc,v 1.2 2022/04/18 11:18:19 adam Exp $

--- src/3rdparty/chromium/content/browser/v8_snapshot_files.cc.orig	2021-02-19 16:41:59.000000000 +0000
+++ src/3rdparty/chromium/content/browser/v8_snapshot_files.cc
@@ -10,7 +10,7 @@
 namespace content {
 
 std::map<std::string, base::FilePath> GetV8SnapshotFilesToPreload() {
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 #if defined(USE_V8_CONTEXT_SNAPSHOT)
   return {{kV8ContextSnapshotDataDescriptor,
            base::FilePath(FILE_PATH_LITERAL(V8_CONTEXT_SNAPSHOT_FILENAME))}};
