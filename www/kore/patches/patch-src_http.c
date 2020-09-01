$NetBSD: patch-src_http.c,v 1.2 2020/09/01 19:25:00 fcambus Exp $

--- src/http.c.orig	2020-08-26 07:20:35.000000000 +0000
+++ src/http.c
@@ -1002,7 +1002,7 @@ http_argument_urldecode(char *arg)
 			return (KORE_RESULT_ERROR);
 		}
 
-		if (!isxdigit(*(p + 1)) || !isxdigit(*(p + 2))) {
+		if (!isxdigit((unsigned char)*(p + 1)) || !isxdigit((unsigned char)*(p + 2))) {
 			*in++ = *p++;
 			continue;
 		}
