$NetBSD: patch-src_string__utils.h,v 1.1 2020/11/19 11:03:04 nia Exp $

Arguments to ctype functions must be unsigned char.

--- src/string_utils.h.orig	2020-10-24 08:44:12.000000000 +0000
+++ src/string_utils.h
@@ -37,7 +37,7 @@ static inline int uitostr(unsigned int n
 static inline const char *skip_space_const(const char *src) {
 	if (!src)
 		return NULL;
-	while (*src && isspace(*src))
+	while (*src && isspace((unsigned char)*src))
 		src++;
 	return src;
 }
@@ -45,7 +45,7 @@ static inline const char *skip_space_con
 static inline char *skip_space_mut(char *src) {
 	if (!src)
 		return NULL;
-	while (*src && isspace(*src))
+	while (*src && isspace((unsigned char)*src))
 		src++;
 	return src;
 }
