$NetBSD: patch-common_nums.c,v 1.1 2022/01/07 12:43:14 nia Exp $

- Fix implicit declaration warnings.

--- common/nums.c.orig	1995-05-09 08:06:46.000000000 +0000
+++ common/nums.c
@@ -21,6 +21,8 @@
  */
 
 #include <sys/time.h>
+#include <stdlib.h>
+#include <ctype.h>
 
 int num_random();
 long num_decimal(char *, int);
