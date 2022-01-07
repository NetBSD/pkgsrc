$NetBSD: patch-common_tmpfile.c,v 1.1 2022/01/07 12:43:14 nia Exp $

- Fix implicit declaration warnings.

--- common/tmpfile.c.orig	1995-05-09 08:06:46.000000000 +0000
+++ common/tmpfile.c
@@ -21,6 +21,7 @@
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
+#include <unistd.h>
 
 /* Data structure describing a temporary file */
 typedef struct tmp_struct {
