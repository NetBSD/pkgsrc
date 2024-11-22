$NetBSD: patch-src_yodl2html-post_yodl2html-post.c,v 1.1 2024/11/22 07:20:51 wiz Exp $

Add header for basename().

--- src/yodl2html-post/yodl2html-post.c.orig	2024-11-22 07:18:50.029173186 +0000
+++ src/yodl2html-post/yodl2html-post.c
@@ -2,6 +2,8 @@
 #define EXTERN
 #include "yodl2html-post.h"
 
+#include <libgen.h>
+
 int 
 main (int argc, char **argv)
 {
