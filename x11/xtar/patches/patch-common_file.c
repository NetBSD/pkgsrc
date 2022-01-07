$NetBSD: patch-common_file.c,v 1.1 2022/01/07 12:43:14 nia Exp $

- Fix implicit declaration warnings.

--- common/file.c.orig	1995-05-09 08:06:46.000000000 +0000
+++ common/file.c
@@ -22,7 +22,9 @@
 #include <sys/stat.h>
 #include <sys/time.h>
 #include <stdio.h>
+#include <stdlib.h>
 #include <string.h>
+#include <unistd.h>
 #include <utime.h>
 #include <time.h>
 
