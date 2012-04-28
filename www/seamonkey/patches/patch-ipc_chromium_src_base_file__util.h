$NetBSD: patch-ipc_chromium_src_base_file__util.h,v 1.4 2012/04/28 22:48:06 ryoon Exp $

--- mozilla/ipc/chromium/src/base/file_util.h.orig	2012-04-23 06:27:38.000000000 +0000
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
