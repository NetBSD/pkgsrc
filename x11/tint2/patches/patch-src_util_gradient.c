$NetBSD: patch-src_util_gradient.c,v 1.1 2022/04/12 13:45:58 tnn Exp $

for bzero(3) on SunOS

--- src/util/gradient.c.orig	2021-12-04 09:46:45.000000000 +0000
+++ src/util/gradient.c
@@ -3,6 +3,7 @@
 #include <glib.h>
 #include <stdlib.h>
 #include <string.h>
+#include <strings.h>
 
 #include "common.h"
 
