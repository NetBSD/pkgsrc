$NetBSD: patch-ConfigureChecks.cmake,v 1.1 2020/11/07 10:30:20 nia Exp $

[PATCH] Fix build with icu-68.1

https://github.com/libical/libical/commit/a3308a23912bba2db654a8c456165c31888cc897.patch

--- ConfigureChecks.cmake.orig	2020-03-07 14:42:42.000000000 +0000
+++ ConfigureChecks.cmake
@@ -10,6 +10,7 @@ check_include_files(sys/utsname.h HAVE_S
 check_include_files(fcntl.h HAVE_FCNTL_H)
 check_include_files(unistd.h HAVE_UNISTD_H)
 check_include_files(wctype.h HAVE_WCTYPE_H)
+check_include_files(stdbool.h HAVE_STDBOOL_H)
 
 include(CheckFunctionExists)
 if(WIN32 AND MSVC)
