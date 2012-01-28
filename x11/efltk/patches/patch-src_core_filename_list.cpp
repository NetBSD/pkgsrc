$NetBSD: patch-src_core_filename_list.cpp,v 1.1 2012/01/28 11:35:26 marino Exp $

--- src/core/filename_list.cpp.orig	2003-01-26 01:16:49.000000000 +0000
+++ src/core/filename_list.cpp
@@ -49,7 +49,7 @@ int fl_filename_list(const char *dir, di
 #if defined(__hpux)
     // HP-UX defines the comparison function like this:
     return scandir(dir, list, 0, (int(*)(const dirent **, const dirent **))sort);
-#elif defined(__osf__)
+#elif defined(__osf__) || defined(__DragonFly__)
     // OSF, DU 4.0x
     return scandir(dir, list, 0, (int(*)(dirent **, dirent **))sort);
 #elif defined(_AIX)
