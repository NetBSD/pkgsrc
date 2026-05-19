$NetBSD: patch-kitty_disk-cache.c,v 1.1 2026/05/19 14:59:16 ktnb Exp $

explicit_zero(3) doesn't exist on NetBSD. See
https://github.com/kovidgoyal/kitty/issues/10037.

--- kitty/disk-cache.c.orig	2026-05-19 13:20:35.821491917 +0000
+++ kitty/disk-cache.c
@@ -48,6 +48,8 @@ static void free_cache_value(CacheValue *cv) {
 static void free_cache_value(CacheValue *cv) {
 #ifdef __APPLE__
     memset_s(cv->encryption_key, sizeof(cv->encryption_key), 0, sizeof(cv->encryption_key));
+#elif defined(__NetBSD__)
+    explicit_memset(cv->encryption_key, 0, sizeof(cv->encryption_key));
 #else
     explicit_bzero(cv->encryption_key, sizeof(cv->encryption_key));
 #endif
