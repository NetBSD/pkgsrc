$NetBSD: patch-src_Script_Instructions.c,v 1.1 2025/10/23 01:28:09 gutteridge Exp $

Use ctype.h correctly.

--- src/Script/Instructions.c.orig	2013-05-01 13:34:11.000000000 +0000
+++ src/Script/Instructions.c
@@ -207,7 +207,7 @@ FuncGetASoption (int *NbArg, long *TabAr
 /* Now seek for wordtofind in &BufCom[int] */
   while ((&BufCom[k] != (char *) 0) && (BufCom[k] != '\0') && (found == 0))
     {
-      while (isspace (*&BufCom[k]))
+      while (isspace ((unsigned char)*&BufCom[k]))
 	BufCom[k]++;
 
       if (mystrncasecmp (&BufCom[k], wordtofind, strlen (wordtofind)) == 0)
