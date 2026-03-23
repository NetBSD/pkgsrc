$NetBSD: patch-libi3_get__process__filename.c,v 1.1 2026/03/23 13:09:13 nia Exp $

Include <libgen.h> for mkdirp(3) on SunOS.

--- libi3/get_process_filename.c.orig	2026-02-06 07:30:55.000000000 +0000
+++ libi3/get_process_filename.c
@@ -10,6 +10,7 @@
 #include <err.h>
 #include <pwd.h>
 #include <stdlib.h>
+#include <libgen.h>
 #include <sys/stat.h>
 #include <unistd.h>
 
