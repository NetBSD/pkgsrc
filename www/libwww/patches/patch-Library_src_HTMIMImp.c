$NetBSD: patch-Library_src_HTMIMImp.c,v 1.1 2018/06/24 16:54:59 adam Exp $

Fix buidling.

--- Library/src/HTMIMImp.c.orig	Mon Feb 22 16:10:11 1999
+++ Library/src/HTMIMImp.c
@@ -226,7 +226,7 @@
     int value = deflt;
     if (start != NULL) {
 	start += strlen(needle);
-	while isspace(*start) start++;
+	while (isspace(*start)) start++;
 	if (isdigit(*start)) {
 	    char * end = start + 1;
 	    char save;
