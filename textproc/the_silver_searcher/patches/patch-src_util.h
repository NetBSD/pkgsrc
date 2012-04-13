$NetBSD: patch-src_util.h,v 1.1.1.1 2012/04/13 11:32:58 wiz Exp $

Add header for struct timeval.

--- src/util.h.orig	2012-04-11 04:05:42.000000000 +0000
+++ src/util.h
@@ -2,6 +2,7 @@
 #define UTIL_H
 
 #include <string.h>
+#include <sys/time.h>
 
 #include "config.h"
 
