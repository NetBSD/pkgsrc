$NetBSD: patch-9wm.c,v 1.2 2024/10/10 17:23:12 nia Exp $

Include sys/select.h for select(2)
Include sys/time.h for struct timeval

--- 9wm.c.orig	2022-01-19 17:57:32.000000000 +0000
+++ 9wm.c
@@ -5,6 +5,8 @@
 #include <signal.h>
 #include <errno.h>
 #include <stdlib.h>
+#include <sys/select.h>
+#include <sys/time.h>
 #include <sys/wait.h>
 #include <X11/X.h>
 #include <X11/Xos.h>
