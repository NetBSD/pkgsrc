$NetBSD: patch-src_fbreader.c,v 1.1 2026/03/22 13:12:59 nia Exp $

Fix implicit declaration of fcntl(2) on SunOS.

--- src/fbreader.c.orig	2026-03-22 13:00:20.271822684 +0000
+++ src/fbreader.c
@@ -26,7 +26,7 @@
 
 #include <sys/types.h>
 #include <sys/stat.h>
-#include <sys/fcntl.h>
+#include <fcntl.h>
 #include <string.h>
 #include <unistd.h>
 #include <sys/stat.h>
