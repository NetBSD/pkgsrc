$NetBSD: patch-src_io.c,v 1.1 2026/03/22 13:12:59 nia Exp $

Fix implicit declaration of fcntl(2) on SunOS.

--- src/io.c.orig	2026-03-22 12:52:22.838136157 +0000
+++ src/io.c
@@ -29,9 +29,9 @@
 
 #include <sys/types.h>
 #include <sys/stat.h>
-#include <sys/fcntl.h>
 #include <sys/wait.h>
 #include <string.h>
+#include <fcntl.h>
 #include <unistd.h>
 #include <stdio.h>
 #include <stdlib.h>
