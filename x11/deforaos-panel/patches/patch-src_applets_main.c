$NetBSD: patch-src_applets_main.c,v 1.3 2014/10/24 23:43:17 khorben Exp $

Need fcntl.h for open() on SunOS.

--- src/applets/main.c.orig	2014-10-23 17:34:42.000000000 +0000
+++ src/applets/main.c
@@ -16,6 +16,9 @@
 
 
 #include <sys/stat.h>
+#if defined(__sun)
+# include <fcntl.h>
+#endif
 #include <dirent.h>
 #include <unistd.h>
 #include <stdlib.h>
