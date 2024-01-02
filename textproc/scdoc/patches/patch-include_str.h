$NetBSD: patch-include_str.h,v 1.1 2024/01/02 17:57:29 schmonz Exp $

Satisfy -Wstrict-prototypes to fix at least macOS build.

--- include/str.h.orig	2020-02-14 21:38:03.000000000 +0000
+++ include/str.h
@@ -7,7 +7,7 @@ struct str {
 	size_t len, size;
 };
 
-struct str *str_create();
+struct str *str_create(void);
 void str_free(struct str *str);
 void str_reset(struct str *str);
 int str_append_ch(struct str *str, uint32_t ch);
