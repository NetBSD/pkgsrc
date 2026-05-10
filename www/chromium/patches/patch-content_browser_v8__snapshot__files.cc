$NetBSD: patch-content_browser_v8__snapshot__files.cc,v 1.19 2026/05/10 15:29:58 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- content/browser/v8_snapshot_files.cc.orig	2026-04-28 23:05:57.000000000 +0200
+++ content/browser/v8_snapshot_files.cc
@@ -41,7 +41,7 @@ void registerContextSnapshotAndroid(
 std::map<std::string, std::variant<base::FilePath, base::ScopedFD>>
 GetV8SnapshotFilesToPreload(base::CommandLine& process_command_line) {
   std::map<std::string, std::variant<base::FilePath, base::ScopedFD>> files;
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #if BUILDFLAG(USE_V8_CONTEXT_SNAPSHOT)
   files[kV8ContextSnapshotDataDescriptor] = base::FilePath(
       FILE_PATH_LITERAL(BUILDFLAG(V8_CONTEXT_SNAPSHOT_FILENAME)));
