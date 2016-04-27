$NetBSD: patch-ipc_chromium_src_base_file__util__posix.cc,v 1.1 2016/04/27 16:36:50 ryoon Exp $

* Just because OS_ARCH is Darwin does not mean MacOS X specific
  implementation should be used.

--- ipc/chromium/src/base/file_util_posix.cc.orig	2015-08-07 15:54:10.000000000 +0000
+++ ipc/chromium/src/base/file_util_posix.cc
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
