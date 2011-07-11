$NetBSD: patch-ipc_chromium_src_base_file__util.h,v 1.1 2011/07/11 20:46:36 tnn Exp $

--- mozilla/ipc/chromium/src/base/file_util.h.orig	2011-06-15 21:57:27.000000000 +0000
+++ mozilla/ipc/chromium/src/base/file_util.h
@@ -15,8 +15,9 @@
 #elif defined(ANDROID)
 #include <sys/stat.h>
 #elif defined(OS_POSIX) 
-#include <fts.h>
+#include <sys/types.h>
 #include <sys/stat.h>
+#include <fts.h>
 #endif
 
 #include <stdio.h>
