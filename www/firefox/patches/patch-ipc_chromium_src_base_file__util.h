$NetBSD: patch-ipc_chromium_src_base_file__util.h,v 1.4 2014/02/20 13:19:03 ryoon Exp $

--- ipc/chromium/src/base/file_util.h.orig	2013-12-05 16:07:35.000000000 +0000
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
 
