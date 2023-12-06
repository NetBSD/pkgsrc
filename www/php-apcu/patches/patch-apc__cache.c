$NetBSD: patch-apc__cache.c,v 1.1 2023/12/06 01:05:13 gdt Exp $

Fix printf specifiers for values of time_t and zend_long.  Upstream
zend actually defines PRI macros for zend_long, which can be int64_t
or int32_t.  Choose a long line vs wrapping to make the diff to
upstream cleaner.  (Observed when building on earmv7hf-el.)

https://github.com/krakjoe/apcu/issues/501

--- apc_cache.c.orig	2023-11-11 17:35:28.000000000 +0000
+++ apc_cache.c
@@ -212,8 +212,8 @@ static void apc_cache_wlocked_gc(apc_cac
 				/* good ol' whining */
 				if (dead->ref_count > 0) {
 					apc_debug(
-						"GC cache entry '%s' was on gc-list for %ld seconds",
-						ZSTR_VAL(dead->key), gc_sec
+						"GC cache entry '%s' was on gc-list for %jd seconds",
+						ZSTR_VAL(dead->key), (intmax_t) gc_sec
 					);
 				}
 
@@ -275,7 +275,7 @@ PHP_APCU_API int APC_UNSERIALIZER_NAME(p
 	BG(serialize_lock)--;
 	
 	if (!result) {
-		php_error_docref(NULL, E_NOTICE, "Error at offset %ld of %ld bytes", (zend_long)(tmp - buf), (zend_long)buf_len);
+		php_error_docref(NULL, E_NOTICE, "Error at offset " ZEND_LONG_FMT " of " ZEND_LONG_FMT " bytes", (zend_long)(tmp - buf), (zend_long)buf_len);
 		ZVAL_NULL(value);
 		return 0;
 	}
