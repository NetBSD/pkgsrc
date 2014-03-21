$NetBSD: patch-src_applets_main.c,v 1.1 2014/03/21 14:38:01 jperkin Exp $

Need sys/fcntl.h for O_RDONLY on SunOS.

--- src/applets/main.c.orig	2013-06-01 23:34:31.000000000 +0000
+++ src/applets/main.c
@@ -23,6 +23,9 @@
 #include <errno.h>
 #include <libintl.h>
 #include <System.h>
+#ifdef __sun
+#include <sys/fcntl.h>
+#endif
 #include "Panel.h"
 #include "../../config.h"
 #define _(string) gettext(string)
