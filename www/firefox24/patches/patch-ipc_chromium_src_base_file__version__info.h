$NetBSD: patch-ipc_chromium_src_base_file__version__info.h,v 1.1 2013/11/03 04:51:59 ryoon Exp $

* Treat Solaris/SunOS like Linux, fix build.

--- ipc/chromium/src/base/file_version_info.h.orig	2013-09-11 03:22:31.000000000 +0000
+++ ipc/chromium/src/base/file_version_info.h
@@ -86,7 +86,7 @@ class FileVersionInfo {
   explicit FileVersionInfo(NSBundle *bundle);
 
   NSBundle *bundle_;
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_SOLARIS)
   FileVersionInfo();
 #endif
 
