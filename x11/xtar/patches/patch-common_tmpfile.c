$NetBSD: patch-common_tmpfile.c,v 1.2 2022/01/07 13:02:31 nia Exp $

- Fix implicit declaration warnings.

--- common/tmpfile.c.orig	1995-05-09 08:06:46.000000000 +0000
+++ common/tmpfile.c
@@ -21,6 +21,8 @@
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
+#include <unistd.h>
+#include "file.h"
 
 /* Data structure describing a temporary file */
 typedef struct tmp_struct {
