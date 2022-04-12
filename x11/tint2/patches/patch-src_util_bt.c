$NetBSD: patch-src_util_bt.c,v 1.1 2022/04/12 13:45:58 tnn Exp $

for bzero(3) on SunOS

--- src/util/bt.c.orig	2021-12-04 09:46:45.000000000 +0000
+++ src/util/bt.c
@@ -21,6 +21,7 @@
 #include <stdint.h>
 #include <stdlib.h>
 #include <string.h>
+#include <strings.h>
 #include <sys/types.h>
 #include <unistd.h>
 #include <stdio.h>
