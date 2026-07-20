$NetBSD: patch-src_common_string-helpers.c,v 1.1 2026/07/20 17:42:40 kikadf Exp $

* Fix ctype usage

--- src/common/string-helpers.c.orig	2026-07-20 14:31:10.046865838 +0000
+++ src/common/string-helpers.c
@@ -28,7 +28,7 @@ rtrim(char *s)
 		return;
 	}
 	char *end = s + len - 1;
-	while (end >= s && isspace(*end)) {
+	while (end >= s && isspace((unsigned char)*end)) {
 		end--;
 	}
 	*(end + 1) = '\0';
@@ -37,7 +37,7 @@ rtrim(char *s)
 char *
 string_strip(char *s)
 {
-	while (isspace(*s)) {
+	while (isspace((unsigned char)*s)) {
 		s++;
 	}
 	rtrim(s);
@@ -200,7 +200,7 @@ bool
 str_space_only(const char *s)
 {
 	for (; *s; s++) {
-		if (!isspace(*s)) {
+		if (!isspace((unsigned char)*s)) {
 			return false;
 		}
 	}
