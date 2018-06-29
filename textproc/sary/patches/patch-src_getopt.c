$NetBSD: patch-src_getopt.c,v 1.1 2018/06/29 17:01:16 taca Exp $

* include <string.h>.

--- src/getopt.c.orig	2004-06-11 18:57:27.000000000 +0000
+++ src/getopt.c
@@ -31,6 +31,10 @@
 #include <config.h>
 #endif
 
+#ifdef HAVE_STRING_H
+#include <string.h>
+#endif
+
 #if !defined (__STDC__) || !__STDC__
 /* This is a separate conditional since some stdc systems
    reject `defined (const)'.  */
