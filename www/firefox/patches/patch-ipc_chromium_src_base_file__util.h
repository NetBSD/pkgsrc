$NetBSD: patch-ipc_chromium_src_base_file__util.h,v 1.3 2014/02/08 09:36:00 ryoon Exp $

--- ipc/chromium/src/base/file_util.h.orig	2014-01-28 04:03:44.000000000 +0000
+++ ipc/chromium/src/base/file_util.h
@@ -16,7 +16,9 @@
 #include <sys/stat.h>
 #elif defined(OS_POSIX) 
 #include <sys/types.h>
+#if !defined(OS_SOLARIS)
 #include <fts.h>
+#endif
 #include <sys/stat.h>
 #endif
 
