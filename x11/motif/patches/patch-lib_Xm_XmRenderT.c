$NetBSD: patch-lib_Xm_XmRenderT.c,v 1.1 2022/04/05 09:59:56 riastradh Exp $

Fix ctype(3) abuse.

--- lib/Xm/XmRenderT.c.orig	2017-03-27 22:24:31.000000000 +0000
+++ lib/Xm/XmRenderT.c
@@ -2788,7 +2788,7 @@ ReadToken(char *string, int *position)
   int count;
 
   /* Skip whitespace but not newlines */
-  while (isspace(string[pos]) && ! (string[pos] == '\n'))
+  while (isspace((unsigned char)string[pos]) && ! (string[pos] == '\n'))
     pos++;
 
   /* Select token type */
@@ -2828,12 +2828,12 @@ ReadToken(char *string, int *position)
     }
     break;
   default:
-    if (isalpha(string[pos])) /* String result */
+    if (isalpha((unsigned char)string[pos])) /* String result */
       {
 	char temp[80];
 	int count;
 	for(count = 0; 
-	    isalpha(string[pos + count]) && count < 79;
+	    isalpha((unsigned char)string[pos + count]) && count < 79;
 	    count++) temp[count] = string[pos + count];
 	temp[count] = 0;
 	pos += count;
