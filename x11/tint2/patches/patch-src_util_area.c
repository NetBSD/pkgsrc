$NetBSD: patch-src_util_area.c,v 1.1 2022/04/12 13:49:38 tnn Exp $

for bzero(3) on SunOS

--- src/util/area.c.orig	2021-12-04 09:46:45.000000000 +0000
+++ src/util/area.c
@@ -26,6 +26,7 @@
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
+#include <strings.h>
 #include <pango/pangocairo.h>
 
 #include "area.h"
