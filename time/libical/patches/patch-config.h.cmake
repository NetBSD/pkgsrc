$NetBSD: patch-config.h.cmake,v 1.1 2020/11/07 10:30:20 nia Exp $

[PATCH] Fix build with icu-68.1

https://github.com/libical/libical/commit/a3308a23912bba2db654a8c456165c31888cc897.patch

--- config.h.cmake.orig	2020-03-07 14:42:42.000000000 +0000
+++ config.h.cmake
@@ -39,6 +39,9 @@
 /* Define to 1 if you have the <dirent.h> header file. */
 #cmakedefine HAVE_DIRENT_H 1
 
+/* Define to 1 if you have the <stdbool.h> header file. */
+#cmakedefine HAVE_STDBOOL_H 1
+
 /* Define if we have pthread. */
 #cmakedefine HAVE_PTHREAD_ATTR_GET_NP 1
 #cmakedefine HAVE_PTHREAD_GETATTR_NP 1
