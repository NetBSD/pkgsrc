$NetBSD: patch-src_error.c,v 1.1 2020/03/22 22:45:00 roy Exp $

va_list requires stdarg.h

--- src/error.c.orig	2020-03-22 22:27:42.074306097 +0000
+++ src/error.c	2020-03-22 22:28:19.609993187 +0000
@@ -32,6 +32,7 @@
 #include <config.h>
 #endif
 
+#include <stdarg.h>
 #include <stdio.h>
 #include <stdlib.h>
 #include <signal.h>
