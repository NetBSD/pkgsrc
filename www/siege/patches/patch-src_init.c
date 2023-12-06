$NetBSD: patch-src_init.c,v 1.2 2023/12/06 15:56:56 abs Exp $

Signals are defined in signal.h in *BSD

Submitted upstream as https://github.com/JoeDog/siege/pull/230

--- src/init.c.orig	2017-09-11 17:36:08.000000000 +0000
+++ src/init.c
@@ -39,7 +39,10 @@
 #include <unistd.h>
 #include <errno.h>
 #include <stdlib.h>
-
+/* Signals are defined in signal.h in *BSD */
+#if defined(__OpenBSD__) || defined(__FreeBSD__) || defined(__NetBSD__) || defined(__DragonFly__)
+#include <signal.h>
+#endif
 #define LINESZ 1024
 
 int
