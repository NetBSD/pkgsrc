$NetBSD: patch-common_mkdirhier.c,v 1.1 2022/01/07 13:02:31 nia Exp $

- Fix implicit declaration warnings.

--- common/mkdirhier.c.orig	1995-05-09 08:06:46.000000000 +0000
+++ common/mkdirhier.c
@@ -24,7 +24,9 @@
 #include <string.h>
 #include <sys/stat.h>
 
+#include "file.h"
 #include "fname.h"
+#include "stat.h"
 
 int mkdirhier(char *, mode_t);
 
