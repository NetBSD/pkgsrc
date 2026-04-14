$NetBSD: patch-common_stringop.c,v 1.1 2026/04/14 11:32:14 kikadf Exp $

* Fix ctype usage

--- common/stringop.c.orig	2026-02-06 15:04:53.573026504 +0000
+++ common/stringop.c
@@ -18,7 +18,7 @@ void strip_whitespace(char *str) {
 	memmove(str, &str[start], len + 1 - start);
 
 	if (*str) {
-		for (len -= start + 1; isspace(str[len]); --len) {}
+		for (len -= start + 1; isspace((unsigned char)str[len]); --len) {}
 		str[len + 1] = '\0';
 	}
 }
