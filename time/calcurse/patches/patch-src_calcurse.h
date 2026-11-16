$NetBSD: patch-src_calcurse.h,v 1.1 2026/11/16 19:17:58 vins Exp $

Needed for va_list.

--- src/calcurse.h.orig	2026-11-16 19:07:42.224530998 +0000
+++ src/calcurse.h
@@ -54,6 +54,7 @@
 #include <stdlib.h>
 #include <stdio.h>
 #include <regex.h>
+#include <stdarg.h>
 
 #include "llist.h"
 #include "vector.h"
