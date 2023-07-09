$NetBSD: patch-lib_ltrcc.c,v 1.1 2023/07/09 20:35:20 jperkin Exp $

Include limits.h for ULONG_MAX.

--- lib/ltrcc.c.orig	2022-05-25 12:00:29.000000000 +0000
+++ lib/ltrcc.c
@@ -37,6 +37,7 @@
 #if defined HAVE_CONFIG_H
 # include "config.h"
 #endif	/* HAVE_CONFIG_H */
+#include <limits.h>
 #include <unistd.h>
 #include <stdlib.h>
 #include <stdint.h>
