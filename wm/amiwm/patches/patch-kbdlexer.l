$NetBSD: patch-kbdlexer.l,v 1.1 2017/01/05 09:40:00 jperkin Exp $

Ensure the local yywrap is used.

--- kbdlexer.l.orig	1998-03-15 19:46:16.000000000 +0000
+++ kbdlexer.l
@@ -10,6 +10,7 @@ extern char *progname;
 
 #ifdef FLEX_SCANNER
 
+#undef yywrap
 #undef YY_INPUT
 #define YY_INPUT(buf,result,size) ((result) = doinput((buf),(size)))
 int doinput (char *buf, int size)
