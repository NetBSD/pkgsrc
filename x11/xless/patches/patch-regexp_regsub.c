$NetBSD: patch-regexp_regsub.c,v 1.1 2018/09/29 12:59:24 tnn Exp $

remove wrong extern prototype for strncpy

--- regexp/regsub.c.orig	1994-06-16 22:29:08.000000000 +0000
+++ regexp/regsub.c
@@ -43,9 +43,6 @@ char *dest;
 	register char c;
 	register int no;
 	register int len;
-#ifndef AIXV3
-	extern char *strncpy();
-#endif
 
 	if (prog == NULL || source == NULL || dest == NULL) {
 		regerror("NULL parm to regsub");
