$NetBSD: patch-src_vte.cc,v 1.1 2018/05/15 09:50:49 jperkin Exp $

Use correct includes on SunOS.

--- src/vte.cc.orig	2018-04-09 21:43:51.000000000 +0000
+++ src/vte.cc
@@ -25,6 +25,9 @@
 #include <string.h>
 #include <sys/ioctl.h>
 #include <sys/param.h> /* howmany() */
+#ifdef __sun
+#include <sys/ptyvar.h>
+#endif
 #include <errno.h>
 #include <fcntl.h>
 #include <math.h>
