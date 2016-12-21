$NetBSD: patch-src_core_filename_list.cpp,v 1.3 2016/12/21 13:40:24 joerg Exp $

--- src/core/filename_list.cpp.orig	2003-01-26 01:16:49.000000000 +0000
+++ src/core/filename_list.cpp
@@ -41,12 +41,16 @@
 						int (*compar)(dirent **, dirent **));
 #endif
 
+#ifdef __NetBSD__
+#include <sys/param.h>
+#endif
+
 int fl_alphasort(struct dirent **a, struct dirent **b) { return strcmp((*a)->d_name, (*b)->d_name); }
 int fl_casealphasort(struct dirent **a, struct dirent **b) { return strcasecmp((*a)->d_name, (*b)->d_name); }
 
 int fl_filename_list(const char *dir, dirent ***list, Fl_File_Sort_F *sort) 
 {
-#if defined(__hpux)
+#if defined(__hpux) || defined(__DragonFly__) || (defined (__NetBSD__) && __NetBSD_Version__-0 >= 799005100)
     // HP-UX defines the comparison function like this:
     return scandir(dir, list, 0, (int(*)(const dirent **, const dirent **))sort);
 #elif defined(__osf__)
