$NetBSD: patch-locale.cpp,v 1.1 2020/03/24 04:08:55 gutteridge Exp $

Fix SunOS build.

--- locale.cpp.orig	1970-01-01 00:00:00.000000000 +0000
+++ locale.cpp
@@ -27,7 +27,11 @@
 #if defined(_MSC_VER) || defined(__WIN32)
 #include <windows.h>
 #else
-#include <sys/fcntl.h>
+#  ifdef __sun
+#    include <fcntl.h>
+#  else
+#    include <sys/fcntl.h>
+#  endif
 #include <sys/stat.h>
 #include <sys/mman.h>
 #endif
