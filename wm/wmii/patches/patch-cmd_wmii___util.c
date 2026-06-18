$NetBSD: patch-cmd_wmii___util.c,v 1.1 2026/06/18 19:46:43 nia Exp $

Fix implicit declaration of kill(2) by including the right
header.

--- cmd/wmii/_util.c.orig	2026-06-18 19:42:16.704038138 +0000
+++ cmd/wmii/_util.c
@@ -5,7 +5,7 @@
 #include <errno.h>
 #include <fcntl.h>
 #include <stdarg.h>
-#include <sys/signal.h>
+#include <signal.h>
 #include <sys/wait.h>
 #include <unistd.h>
 #include <bio.h>
