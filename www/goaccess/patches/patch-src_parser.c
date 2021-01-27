$NetBSD: patch-src_parser.c,v 1.1 2021/01/27 08:17:31 schmonz Exp $

Remove non-portable include.

--- src/parser.c.orig	2020-05-17 15:46:01.000000000 +0000
+++ src/parser.c
@@ -54,7 +54,6 @@
 #include <sys/stat.h>
 #include <sys/types.h>
 #include <unistd.h>
-#include <malloc.h>
 
 #include "gkhash.h"
 
