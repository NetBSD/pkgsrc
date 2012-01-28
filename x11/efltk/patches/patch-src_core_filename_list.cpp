$NetBSD: patch-src_core_filename_list.cpp,v 1.2 2012/01/28 11:59:06 marino Exp $

--- src/core/filename_list.cpp.orig	2003-01-26 01:16:49.000000000 +0000
+++ src/core/filename_list.cpp
@@ -46,7 +46,7 @@ int fl_casealphasort(struct dirent **a,
 
 int fl_filename_list(const char *dir, dirent ***list, Fl_File_Sort_F *sort) 
 {
-#if defined(__hpux)
+#if defined(__hpux) || defined(__DragonFly__)
     // HP-UX defines the comparison function like this:
     return scandir(dir, list, 0, (int(*)(const dirent **, const dirent **))sort);
 #elif defined(__osf__)
