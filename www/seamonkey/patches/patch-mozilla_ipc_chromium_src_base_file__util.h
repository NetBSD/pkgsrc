$NetBSD: patch-mozilla_ipc_chromium_src_base_file__util.h,v 1.2 2013/12/26 13:17:37 ryoon Exp $

--- mozilla/ipc/chromium/src/base/file_util.h.orig	2013-12-11 04:28:40.000000000 +0000
+++ mozilla/ipc/chromium/src/base/file_util.h
@@ -16,7 +16,9 @@
 #include <sys/stat.h>
 #elif defined(OS_POSIX) 
 #include <sys/types.h>
+#if !defined(OS_SOLARIS)
 #include <fts.h>
+#endif
 #include <sys/stat.h>
 #endif
 
