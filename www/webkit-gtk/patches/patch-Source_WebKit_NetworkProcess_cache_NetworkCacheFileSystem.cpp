$NetBSD: patch-Source_WebKit_NetworkProcess_cache_NetworkCacheFileSystem.cpp,v 1.4 2020/09/11 14:47:35 leot Exp $

SunOS does not support DT_{DIR,REG}

--- Source/WebKit/NetworkProcess/cache/NetworkCacheFileSystem.cpp.orig	2020-08-12 09:17:56.000000000 +0000
+++ Source/WebKit/NetworkProcess/cache/NetworkCacheFileSystem.cpp
@@ -36,6 +36,12 @@
 #include <dirent.h>
 #include <sys/stat.h>
 #include <sys/time.h>
+#ifndef DT_DIR
+#define DT_DIR	S_IFDIR
+#endif
+#ifndef DT_REG
+#define DT_REG	S_IFREG
+#endif
 #else
 #include <windows.h>
 #endif
