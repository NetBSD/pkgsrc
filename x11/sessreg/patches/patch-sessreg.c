$NetBSD: patch-sessreg.c,v 1.2 2012/06/10 16:46:01 wiz Exp $

Make sure file name defines exist on NetBSD.
https://bugs.freedesktop.org/show_bug.cgi?id=50940

--- sessreg.c.orig	2011-09-26 23:01:11.000000000 +0000
+++ sessreg.c
@@ -99,6 +99,13 @@ static const char *wtmpx_file = NULL;
 static const char *utmpx_file = NULL;
 #endif
 #endif
+#ifndef WTMPX_FILE
+#define WTMPX_FILE	_PATH_WTMPX
+#endif
+#ifndef UTMPX_FILE
+#define UTMPX_FILE	_PATH_UTMPX
+#endif
+
 static int utmp_none, wtmp_none;
 /*
  * BSD specific variables.  To make life much easier for Xstartup/Xreset
