$NetBSD: patch-build-aux_yuck.c,v 1.1 2018/09/29 17:18:20 wiedi Exp $

no need for sysctl on SunOS
--- build-aux/yuck.c.orig	2018-03-01 09:55:48.000000000 +0000
+++ build-aux/yuck.c
@@ -62,7 +62,9 @@
 #include <sys/wait.h>
 #include <sys/stat.h>
 #include <sys/types.h>
+#if !defined(__sun)
 #include <sys/sysctl.h>
+#endif
 #include <time.h>
 #if defined WITH_SCMVER
 # include <yuck-scmver.h>
