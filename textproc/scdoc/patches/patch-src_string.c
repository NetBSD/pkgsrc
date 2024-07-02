$NetBSD: patch-src_string.c,v 1.2 2024/07/02 12:04:37 tnn Exp $

Satisfy -Wstrict-prototypes to fix at least macOS build.
Satisfy -Werror=calloc-transposed-args (GCC 14)

--- src/string.c.orig	2020-02-14 21:38:03.000000000 +0000
+++ src/string.c
@@ -15,8 +15,8 @@ static int ensure_capacity(struct str *s
 	return 1;
 }
 
-struct str *str_create() {
-	struct str *str = calloc(sizeof(struct str), 1);
+struct str *str_create(void) {
+	struct str *str = calloc(1, sizeof(struct str));
 	str->str = malloc(16);
 	str->size = 16;
 	str->len = 0;
