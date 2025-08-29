$NetBSD: patch-src_util.c,v 1.3 2025/08/29 12:17:50 leot Exp $

Fix ctype(3) abuses

--- src/util.c.orig	2025-08-29 12:08:47.866239353 +0000
+++ src/util.c
@@ -77,8 +77,8 @@ void generate_alpha_skip(const char *fin
         if (case_sensitive) {
             skip_lookup[(unsigned char)find[i]] = f_len - i;
         } else {
-            skip_lookup[(unsigned char)tolower(find[i])] = f_len - i;
-            skip_lookup[(unsigned char)toupper(find[i])] = f_len - i;
+            skip_lookup[(unsigned char)tolower((unsigned char)find[i])] = f_len - i;
+            skip_lookup[(unsigned char)toupper((unsigned char)find[i])] = f_len - i;
         }
     }
 }
@@ -92,7 +92,7 @@ int is_prefix(const char *s, const size_
                 return 0;
             }
         } else {
-            if (tolower(s[i]) != tolower(s[i + pos])) {
+            if (tolower((unsigned char)s[i]) != tolower((unsigned char)s[i + pos])) {
                 return 0;
             }
         }
@@ -110,7 +110,7 @@ size_t suffix_len(const char *s, const s
                 break;
             }
         } else {
-            if (tolower(s[pos - i]) != tolower(s[s_len - i - 1])) {
+            if (tolower((unsigned char)s[pos - i]) != tolower((unsigned char)s[s_len - i - 1])) {
                 break;
             }
         }
@@ -188,7 +188,7 @@ const char *boyer_moore_strnstr(const ch
     size_t pos = f_len - 1;
 
     while (pos < s_len) {
-        for (i = f_len - 1; i >= 0 && (case_insensitive ? tolower(s[pos]) : s[pos]) == find[i]; pos--, i--) {
+        for (i = f_len - 1; i >= 0 && (case_insensitive ? tolower((unsigned char)s[pos]) : s[pos]) == find[i]; pos--, i--) {
         }
         if (i < 0) {
             return s + pos + 1;
@@ -215,7 +215,7 @@ NO_SANITIZE_ALIGNMENT const char *hash_s
             size_t i;
             // Check putative match
             for (i = 0; i < f_len; i++) {
-                if ((case_sensitive ? R[i] : tolower(R[i])) != find[i])
+                if ((case_sensitive ? R[i] : tolower((unsigned char)R[i])) != find[i])
                     goto next_hash_cell;
             }
             return R; // Found
@@ -227,7 +227,7 @@ NO_SANITIZE_ALIGNMENT const char *hash_s
         size_t i;
         const char *R = s + s_i;
         for (i = 0; i < f_len; i++) {
-            char s_c = case_sensitive ? R[i] : tolower(R[i]);
+            char s_c = case_sensitive ? R[i] : tolower((unsigned char)R[i]);
             if (s_c != find[i])
                 goto next_start;
         }
@@ -457,7 +457,7 @@ int is_wordchar(char ch) {
 int is_lowercase(const char *s) {
     int i;
     for (i = 0; s[i] != '\0'; i++) {
-        if (!isascii(s[i]) || isupper(s[i])) {
+        if (!isascii((unsigned char)s[i]) || isupper((unsigned char)s[i])) {
             return FALSE;
         }
     }
