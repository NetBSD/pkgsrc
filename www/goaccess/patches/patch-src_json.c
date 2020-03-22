$NetBSD: patch-src_json.c,v 1.1 2020/03/22 22:45:00 roy Exp $

va_list requires stdarg.h

--- src/json.c.orig	2020-03-22 22:28:55.816959313 +0000
+++ src/json.c	2020-03-22 22:29:26.309825982 +0000
@@ -34,6 +34,7 @@
 
 #include <errno.h>
 #include <ctype.h>
+#include <stdarg.h>
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
