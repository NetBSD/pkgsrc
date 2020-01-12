$NetBSD: patch-src_http.c,v 1.1 2020/01/12 23:01:06 joerg Exp $

--- src/http.c.orig	2020-01-11 18:36:08.320328389 +0000
+++ src/http.c
@@ -983,7 +983,7 @@ http_argument_urldecode(char *arg)
 			return (KORE_RESULT_ERROR);
 		}
 
-		if (!isxdigit(*(p + 1)) || !isxdigit(*(p + 2))) {
+		if (!isxdigit((unsigned char)*(p + 1)) || !isxdigit((unsigned char)*(p + 2))) {
 			*in++ = *p++;
 			continue;
 		}
