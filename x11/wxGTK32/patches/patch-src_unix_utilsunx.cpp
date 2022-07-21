$NetBSD: patch-src_unix_utilsunx.cpp,v 1.1 2022/07/21 11:39:21 wiz Exp $

cmake: prefer statvfs (to statfs)
https://github.com/wxWidgets/wxWidgets/pull/22643

--- src/unix/utilsunx.cpp.orig	2022-07-06 14:19:50.000000000 +0000
+++ src/unix/utilsunx.cpp
@@ -85,7 +85,11 @@
 // different platforms and even different versions of the same system (Solaris
 // 7 and 8): if you want to test for this, don't forget that the problems only
 // appear if the large files support is enabled
-#ifdef HAVE_STATFS
+#if defined(HAVE_STATVFS)
+    #include <sys/statvfs.h>
+
+    #define wxStatfs statvfs
+#elif defined(HAVE_STATFS)
     #ifdef __BSD__
         #include <sys/param.h>
         #include <sys/mount.h>
@@ -99,15 +103,9 @@
         // some systems lack statfs() prototype in the system headers (AIX 4)
         extern "C" int statfs(const char *path, struct statfs *buf);
     #endif
-#endif // HAVE_STATFS
-
-#ifdef HAVE_STATVFS
-    #include <sys/statvfs.h>
-
-    #define wxStatfs statvfs
-#endif // HAVE_STATVFS
+#endif // HAVE_STATVFS/HAVE_STATFS
 
-#if defined(HAVE_STATFS) || defined(HAVE_STATVFS)
+#if defined(HAVE_STATVFS) || defined(HAVE_STATFS)
     // WX_STATFS_T is detected by configure
     #define wxStatfs_t WX_STATFS_T
 #endif
