$NetBSD: patch-include_setproctitle.h,v 1.1 2016/09/20 08:00:51 wiz Exp $

Remove setproctitle, conflicts with NetBSD version and not used
in mcookie.

--- include/setproctitle.h.orig	2015-04-07 09:12:31.000000000 +0000
+++ include/setproctitle.h
@@ -1,7 +1,8 @@
 #ifndef UTIL_LINUX_SETPROCTITLE_H
 #define UTIL_LINUX_SETPROCTITLE_H
 
+#include <stdlib.h>
+
 extern void initproctitle (int argc, char **argv);
-extern void setproctitle (const char *prog, const char *txt);
 
 #endif
