$NetBSD: patch-cgi-bozo.c,v 1.1 2014/01/07 19:35:28 jperkin Exp $

SunOS does not have paths.h

--- cgi-bozo.c.orig	2014-01-02 08:24:28.000000000 +0000
+++ cgi-bozo.c
@@ -39,7 +39,9 @@
 
 #include <ctype.h>
 #include <errno.h>
+#ifndef __sun
 #include <paths.h>
+#endif
 #include <signal.h>
 #include <stdlib.h>
 #include <string.h>
