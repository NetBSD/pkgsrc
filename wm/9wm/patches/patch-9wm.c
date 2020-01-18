$NetBSD: patch-9wm.c,v 1.1 2020/01/18 21:40:24 nia Exp $

Include sys/select.h for select(2)

--- 9wm.c.orig	2018-04-09 21:35:43.000000000 +0000
+++ 9wm.c
@@ -5,6 +5,7 @@
 #include <signal.h>
 #include <errno.h>
 #include <stdlib.h>
+#include <sys/select.h>
 #include <sys/wait.h>
 #include <X11/X.h>
 #include <X11/Xos.h>
