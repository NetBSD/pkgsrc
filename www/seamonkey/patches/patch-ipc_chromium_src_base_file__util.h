$NetBSD: patch-ipc_chromium_src_base_file__util.h,v 1.2 2012/03/10 03:26:05 ryoon Exp $

--- mozilla/ipc/chromium/src/base/file_util.h.orig	2012-02-16 14:09:02.000000000 +0000
+++ mozilla/ipc/chromium/src/base/file_util.h
@@ -16,8 +16,8 @@
 #include <sys/stat.h>
 #elif defined(OS_POSIX) 
 #include <sys/types.h>
-#include <fts.h>
 #include <sys/stat.h>
+#include <fts.h>
 #endif
 
 #include <stdio.h>
