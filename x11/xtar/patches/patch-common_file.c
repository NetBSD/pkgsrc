$NetBSD: patch-common_file.c,v 1.2 2022/01/07 13:02:31 nia Exp $

- Fix implicit declaration warnings.

--- common/file.c.orig	1995-05-09 08:06:46.000000000 +0000
+++ common/file.c
@@ -22,10 +22,13 @@
 #include <sys/stat.h>
 #include <sys/time.h>
 #include <stdio.h>
+#include <stdlib.h>
 #include <string.h>
+#include <unistd.h>
 #include <utime.h>
 #include <time.h>
 
+#include "env.h"
 #include "stat.h"		/* We use stat_size()           */
 #include "fname.h"
 #include "magic.h"
