$NetBSD: patch-src_string.c,v 1.1 2024/01/02 17:57:29 schmonz Exp $

Satisfy -Wstrict-prototypes to fix at least macOS build.

--- src/string.c.orig	2020-02-14 21:38:03.000000000 +0000
+++ src/string.c
@@ -15,7 +15,7 @@ static int ensure_capacity(struct str *s
 	return 1;
 }
 
-struct str *str_create() {
+struct str *str_create(void) {
 	struct str *str = calloc(sizeof(struct str), 1);
 	str->str = malloc(16);
 	str->size = 16;
