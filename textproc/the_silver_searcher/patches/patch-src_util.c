$NetBSD: patch-src_util.c,v 1.1.1.1 2012/04/13 11:32:58 wiz Exp $

Remove header that doesn't exist on NetBSD (and is not missed).

--- src/util.c.orig	2012-04-11 04:05:42.000000000 +0000
+++ src/util.c
@@ -1,7 +1,6 @@
 #include <ctype.h>
 #include <string.h>
 #include <stdio.h>
-#include <xlocale.h>
 #include <stdarg.h>
 #include <strings.h>
 #include <stdlib.h>
