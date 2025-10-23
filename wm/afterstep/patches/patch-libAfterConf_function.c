$NetBSD: patch-libAfterConf_function.c,v 1.1 2025/10/23 01:28:08 gutteridge Exp $

Use ctype.h correctly.

--- libAfterConf/function.c.orig	2013-05-01 13:34:11.000000000 +0000
+++ libAfterConf/function.c
@@ -199,7 +199,7 @@ FunctionData *String2Func (const char *s
 	storage->term = fterm;
 
 	ptr += storage->term->keyword_len;
-	while (!isspace ((int)*ptr) && *ptr)
+	while (!isspace ((unsigned char)*ptr) && *ptr)
 		ptr++;
 	if (!(fterm->flags & NEED_CMD))
 		ptr = stripcomments (ptr);
