$NetBSD: patch-cmd_wmii_main.c,v 1.1 2018/05/14 10:20:57 maya Exp $

signal.h for sigaction, otherwise it dumps core on netbsd/amd64
due to a reference to compat sigaction.

--- cmd/wmii/main.c.orig	2010-06-10 07:24:02.000000000 +0000
+++ cmd/wmii/main.c
@@ -10,6 +10,7 @@
 #include <fcntl.h>
 #include <locale.h>
 #include <pwd.h>
+#include <signal.h>
 #include <sys/signal.h>
 #include <sys/stat.h>
 #include <unistd.h>
