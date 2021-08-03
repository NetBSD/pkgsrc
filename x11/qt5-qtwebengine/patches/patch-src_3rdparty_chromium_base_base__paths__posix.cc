$NetBSD: patch-src_3rdparty_chromium_base_base__paths__posix.cc,v 1.1 2021/08/03 21:04:34 markd Exp $

--- src/3rdparty/chromium/base/base_paths_posix.cc.orig	2020-07-15 18:55:48.000000000 +0000
+++ src/3rdparty/chromium/base/base_paths_posix.cc
@@ -67,7 +67,7 @@ bool PathProviderPosix(int key, FilePath
       }
       *result = FilePath(bin_dir);
       return true;
-#elif defined(OS_OPENBSD) || defined(OS_AIX)
+#elif defined(OS_OPENBSD) || defined(OS_AIX) || defined(OS_NETBSD)
       // There is currently no way to get the executable path on OpenBSD
       char* cpath;
       if ((cpath = getenv("CHROME_EXE_PATH")) != NULL)
