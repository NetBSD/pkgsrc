$NetBSD: patch-common_str.c,v 1.1 2022/01/07 12:43:14 nia Exp $

- Do not define symbols that belong to libc headers.
- Fix implicit declaration warnings.

--- common/str.c.orig	1995-05-09 08:06:46.000000000 +0000
+++ common/str.c
@@ -18,6 +18,7 @@
  *
  */
 
+#include <ctype.h>
 #include <errno.h>
 #include <stdio.h>
 #include <string.h>
@@ -282,8 +283,6 @@ char *str_word(char **string)
   ---------------------------------------------------------------------------*/
 char *str_error(int errnum)
 {
-        extern int sys_nerr;
-        extern char *sys_errlist[];
         static char ebuf[40];           /* 64-bit number + slop */
 
         if ((unsigned int)errnum < sys_nerr)
