$NetBSD: patch-xwatchwin.c,v 1.1 2026/06/20 11:08:35 nia Exp $

Avoid implicit int. Recent GCC no longer likes it.

--- xwatchwin.c.orig	2026-06-20 11:06:24.401871473 +0000
+++ xwatchwin.c
@@ -176,6 +176,7 @@ main(int argc, char **argv)
 
 /* Takes two strings, removes spaces from the second,... */
 /* ...and compares them..  Returns 1 if equal, 0 if not. */
+int
 WinNamesEqual(char *str1, char *str2)
 {
     char            tempStr[STRINGLENGTH], *tempStrPtr;
