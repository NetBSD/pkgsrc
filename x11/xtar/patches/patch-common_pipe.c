$NetBSD: patch-common_pipe.c,v 1.2 2022/01/07 13:02:31 nia Exp $

- Fix implicit declaration warnings.

--- common/pipe.c.orig	1995-05-09 08:06:46.000000000 +0000
+++ common/pipe.c
@@ -23,7 +23,10 @@
 
 #include <errno.h>
 #include <stdio.h>
+#include <stdlib.h>
+#include <string.h>
 #include <fcntl.h>
+#include <unistd.h>
 
 #include "magic.h"
 #include "str.h"
