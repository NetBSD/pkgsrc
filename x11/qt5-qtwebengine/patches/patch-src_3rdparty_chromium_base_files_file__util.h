$NetBSD: patch-src_3rdparty_chromium_base_files_file__util.h,v 1.1 2021/08/03 21:04:34 markd Exp $

--- src/3rdparty/chromium/base/files/file_util.h.orig	2020-06-25 09:31:18.000000000 +0000
+++ src/3rdparty/chromium/base/files/file_util.h
@@ -582,7 +582,7 @@ BASE_EXPORT bool VerifyPathControlledByA
 // the directory |path|, in the number of FilePath::CharType, or -1 on failure.
 BASE_EXPORT int GetMaximumPathComponentLength(const base::FilePath& path);
 
-#if defined(OS_LINUX) || defined(OS_AIX)
+#if defined(OS_LINUX) || defined(OS_AIX) || defined(OS_BSD)
 // Broad categories of file systems as returned by statfs() on Linux.
 enum FileSystemType {
   FILE_SYSTEM_UNKNOWN,  // statfs failed.
