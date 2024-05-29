$NetBSD: patch-locale.cpp,v 1.2 2024/05/29 17:51:10 adam Exp $

Fix SunOS build.

--- locale.cpp.orig	2023-12-22 12:49:23.000000000 +0000
+++ locale.cpp
@@ -28,7 +28,11 @@
 #include <windows.h>
 #else
 #include <unistd.h>
-#include <sys/fcntl.h>
+#  ifdef __sun
+#    include <fcntl.h>
+#  else
+#    include <sys/fcntl.h>
+#  endif
 #include <sys/stat.h>
 #include <sys/mman.h>
 #endif
