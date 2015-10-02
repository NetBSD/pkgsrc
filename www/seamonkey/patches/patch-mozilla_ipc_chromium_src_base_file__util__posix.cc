$NetBSD: patch-mozilla_ipc_chromium_src_base_file__util__posix.cc,v 1.4 2015/10/02 22:49:36 ryoon Exp $

--- mozilla/ipc/chromium/src/base/file_util_posix.cc.orig	2015-09-25 07:35:23.000000000 +0000
+++ mozilla/ipc/chromium/src/base/file_util_posix.cc
@@ -266,7 +266,7 @@ bool SetCurrentDirectory(const FilePath&
   return !ret;
 }
 
-#if !defined(OS_MACOSX)
+#if !defined(MOZ_WIDGET_COCOA)
 bool GetTempDir(FilePath* path) {
   const char* tmp = getenv("TMPDIR");
   if (tmp)
@@ -330,6 +330,6 @@ bool CopyFile(const FilePath& from_path,
 
   return result;
 }
-#endif // !defined(OS_MACOSX)
+#endif // !defined(MOZ_WIDGET_COCOA)
 
 } // namespace file_util
