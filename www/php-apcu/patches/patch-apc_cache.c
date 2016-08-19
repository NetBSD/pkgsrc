$NetBSD: patch-apc_cache.c,v 1.1 2016/08/19 09:34:46 jdolecek Exp $

Fix for SIGSEGvs when memory allocation fails.

https://bugs.php.net/bug.php?id=72801

--- apc_cache.c.orig	2016-06-07 12:41:02.000000000 +0000
+++ apc_cache.c
@@ -46,7 +46,7 @@ typedef int (*ht_check_copy_fun_t)(Bucke
 
 #define CHECK(p) { if ((p) == NULL) return NULL; }
 
-static APC_HOTSPOT void my_copy_zval(zval* dst, const zval* src, apc_context_t* ctxt);
+static APC_HOTSPOT zval* my_copy_zval(zval* dst, const zval* src, apc_context_t* ctxt);
 
 /* {{{ make_prime */
 static int const primes[] = {
@@ -108,22 +108,24 @@ apc_cache_slot_t* make_slot(apc_cache_t*
 		/* copy identifier */
 		zend_string *copiedKey = apc_pstrcpy(key->str, value->pool);
 
-		if (copiedKey) {
+		if (copiedKey == NULL) {
+            value->pool->pfree(value->pool, p);
+            return NULL;
+        }
 			
-			/* set slot data */
-			p->key = key[0];
-			p->key.str = copiedKey;
-			p->value = value;
+		/* set slot data */
+		p->key = key[0];
+		p->key.str = copiedKey;
+		p->value = value;
 
-			/* set slot relation */
-			p->next = next;
+		/* set slot relation */
+		p->next = next;
 			
-			/* set slot defaults */
-			p->nhits = 0;
-			p->ctime = t;
-			p->atime = t;
-			p->dtime = 0;
-		}
+		/* set slot defaults */
+		p->nhits = 0;
+		p->ctime = t;
+		p->atime = t;
+		p->dtime = 0;
 	}
 
     return p;
@@ -232,8 +234,12 @@ PHP_APCU_API int APC_SERIALIZER_NAME(php
     PHP_VAR_SERIALIZE_INIT(var_hash);
     php_var_serialize(&strbuf, (zval*) value, &var_hash);
     PHP_VAR_SERIALIZE_DESTROY(var_hash);
-    if(strbuf.s->val) {
+
+    if (strbuf.s != NULL) {
         *buf = (unsigned char *)estrndup(ZSTR_VAL(strbuf.s), ZSTR_LEN(strbuf.s));
+        if (*buf == NULL)
+            return 0;
+
         *buf_len = ZSTR_LEN(strbuf.s);
 		smart_str_free(&strbuf);
         return 1;
@@ -269,6 +275,11 @@ PHP_APCU_API apc_cache_t* apc_cache_crea
 	/* allocate pointer by normal means */
     cache = (apc_cache_t*) apc_emalloc(sizeof(apc_cache_t));
 
+    if (!cache) {
+        apc_error("Unable to allocate memory for cache structures. (Perhaps your memory_limit isn't large enough?). ");
+        return NULL;
+    }
+	
 	/* calculate cache size for shm allocation */
     cache_size = sizeof(apc_cache_header_t) + nslots*sizeof(apc_cache_slot_t*);
 
@@ -495,12 +506,13 @@ static inline apc_cache_entry_t* apc_cac
 static inline zend_bool apc_cache_fetch_internal(apc_cache_t* cache, zend_string *key, apc_cache_entry_t *entry, time_t t, zval **dst) {
 	/* context for copying out */
 	apc_context_t ctxt = {0, };
+    zval *rv;
 
 	/* create unpool context */
 	if (apc_cache_make_context(cache, &ctxt, APC_CONTEXT_NOSHARE, APC_UNPOOL, APC_COPY_OUT, 0)) {
 
 		/* copy to destination */
-		apc_cache_fetch_zval(&ctxt, *dst, &entry->val);
+		rv = apc_cache_fetch_zval(&ctxt, *dst, &entry->val);
 
 		/* release entry */
 		apc_cache_release(cache, entry);
@@ -508,7 +520,7 @@ static inline zend_bool apc_cache_fetch_
 		/* destroy context */
 		apc_cache_destroy_context(&ctxt );
 
-		return 1;
+		return (rv != NULL) ? 1 : 0;
 	}
 
 	return 0;
@@ -1268,7 +1280,8 @@ static zend_always_inline int apc_array_
 		}
 	} while (0);
 
-	my_copy_zval(&q->val, data, ctxt);
+	if (my_copy_zval(&q->val, data, ctxt) == NULL)
+        return 0;
 
 	q->h = p->h;
 	if (packed) {
@@ -1341,7 +1354,11 @@ static APC_HOTSPOT HashTable* my_copy_ha
 
 	if (ctxt->copy == APC_COPY_IN) {
 		target = (HashTable*) pool->palloc(pool, sizeof(HashTable));
-	} else ALLOC_HASHTABLE(target);
+	} else
+        ALLOC_HASHTABLE(target);
+
+    if (target == NULL)
+        goto bad;
 
 	GC_REFCOUNT(target) = 1;
 	GC_TYPE_INFO(target) = IS_ARRAY;
@@ -1366,7 +1383,12 @@ static APC_HOTSPOT HashTable* my_copy_ha
 		target->nNextFreeElement = source->nNextFreeElement;
 		if (ctxt->copy == APC_COPY_IN) {
 			HT_SET_DATA_ADDR(target, pool->palloc(pool, HT_SIZE(target)));
-		} else HT_SET_DATA_ADDR(target, emalloc(HT_SIZE(target)));
+		} else
+            HT_SET_DATA_ADDR(target, emalloc(HT_SIZE(target)));
+
+        if (HT_GET_DATA_ADDR(target) == NULL)
+            goto bad;
+
 		target->nInternalPointer = source->nInternalPointer;
 		memcpy(HT_GET_DATA_ADDR(target), HT_GET_DATA_ADDR(source), HT_USED_SIZE(source));
 		if (target->nNumOfElements > 0 &&
@@ -1385,7 +1407,12 @@ static APC_HOTSPOT HashTable* my_copy_ha
 		target->nNextFreeElement = source->nNextFreeElement;
 		if (ctxt->copy == APC_COPY_IN) {
 			HT_SET_DATA_ADDR(target, pool->palloc(pool, HT_SIZE(target)));
-		} else	HT_SET_DATA_ADDR(target, emalloc(HT_SIZE(target)));
+		} else
+            HT_SET_DATA_ADDR(target, emalloc(HT_SIZE(target)));
+
+        if (HT_GET_DATA_ADDR(target) == NULL)
+            goto bad;
+
 		target->nInternalPointer = source->nInternalPointer;
 		HT_HASH_RESET_PACKED(target);
 
@@ -1409,7 +1436,12 @@ static APC_HOTSPOT HashTable* my_copy_ha
 		target->nInternalPointer = HT_INVALID_IDX;
 		if (ctxt->copy == APC_COPY_IN) {
 			HT_SET_DATA_ADDR(target, pool->palloc(pool, HT_SIZE(target)));
-		} else HT_SET_DATA_ADDR(target, emalloc(HT_SIZE(target)));
+		} else
+            HT_SET_DATA_ADDR(target, emalloc(HT_SIZE(target)));
+
+        if (HT_GET_DATA_ADDR(target) == NULL)
+            goto bad;
+
 		HT_HASH_RESET(target);
 
 		if (target->u.flags & HASH_FLAG_STATIC_KEYS) {
@@ -1432,6 +1464,18 @@ static APC_HOTSPOT HashTable* my_copy_ha
 		}
 	}
 	return target;
+
+  bad:
+    /* some kind of memory allocation failure */
+    if (target) {
+	    if (ctxt->copy == APC_COPY_IN) {
+            pool->pfree(pool, target);
+	    } else {
+            FREE_HASHTABLE(target);
+        }
+    }
+
+    return NULL;
 }
 
 static APC_HOTSPOT zend_reference* my_copy_reference(const zend_reference* src, apc_context_t *ctxt) {
@@ -1454,10 +1498,14 @@ static APC_HOTSPOT zend_reference* my_co
         dst = emalloc(sizeof(zend_reference));
     }
 
+    if (dst == NULL)
+        return NULL;
+
     GC_REFCOUNT(dst) = 1;
     GC_TYPE_INFO(dst) = IS_REFERENCE;
-	
-    my_copy_zval(&dst->val, &src->val, ctxt);
+
+    if (my_copy_zval(&dst->val, &src->val, ctxt) == NULL)
+        return NULL;
 
 	if (ctxt->copied.nTableSize) {
 		zend_hash_index_update_ptr(&ctxt->copied, (uintptr_t) src, dst);
@@ -1467,7 +1515,7 @@ static APC_HOTSPOT zend_reference* my_co
 }
 
 /* {{{ my_copy_zval */
-static APC_HOTSPOT void my_copy_zval(zval* dst, const zval* src, apc_context_t* ctxt)
+static APC_HOTSPOT zval* my_copy_zval(zval* dst, const zval* src, apc_context_t* ctxt)
 {
     apc_pool* pool = ctxt->pool;
 
@@ -1481,8 +1529,9 @@ static APC_HOTSPOT void my_copy_zval(zva
             zval *rc = zend_hash_index_find(
                     &ctxt->copied, (uintptr_t) Z_COUNTED_P(src));
             if (rc) {
+                /* this does not allocate memory, so always succeeds */
 				ZVAL_COPY(dst, rc);
-				return;
+				return dst;
             }
 		}
 	}
@@ -1497,12 +1546,14 @@ static APC_HOTSPOT void my_copy_zval(zva
         break;
 
 	case IS_REFERENCE:
-		Z_REF_P(dst) = my_copy_reference(Z_REF_P(src), ctxt);
-	break;
+		if ((Z_REF_P(dst) = my_copy_reference(Z_REF_P(src), ctxt)) == NULL)
+            return NULL;
+	    break;
 
 	case IS_INDIRECT:
-		my_copy_zval(dst, Z_INDIRECT_P(src), ctxt);
-	break;
+		if (my_copy_zval(dst, Z_INDIRECT_P(src), ctxt) == NULL)
+            return NULL;
+	    break;
 
     case IS_CONSTANT:
     case IS_STRING:	
@@ -1512,20 +1563,26 @@ static APC_HOTSPOT void my_copy_zval(zva
 			Z_TYPE_INFO_P(dst) = IS_STRING_EX;
 			Z_STR_P(dst) = apc_pstrcpy(Z_STR_P(src), pool);
 		}
+        if (Z_STR_P(dst) == NULL)
+            return NULL;
         break;
 
     case IS_ARRAY:
         if(ctxt->serializer == NULL) {
-			Z_ARRVAL_P(dst) = my_copy_hashtable(Z_ARRVAL_P(src), ctxt);
+			if ((Z_ARRVAL_P(dst) = my_copy_hashtable(Z_ARRVAL_P(src), ctxt)) == NULL)
+                return NULL;
             break;
         }
 
 		/* break intentionally omitted */
 
     case IS_OBJECT:
-        if(ctxt->copy == APC_COPY_IN) {
+        if (ctxt->copy == APC_COPY_IN) {
             dst = my_serialize_object(dst, src, ctxt);
-        } else dst = my_unserialize_object(dst, src, ctxt);
+        } else
+            dst = my_unserialize_object(dst, src, ctxt);
+        if (dst == NULL)
+            return NULL;
         break;
 
     case IS_CALLABLE:
@@ -1540,14 +1597,15 @@ static APC_HOTSPOT void my_copy_zval(zva
 	if (Z_REFCOUNTED_P(dst) && ctxt->copied.nTableSize) {
 		zend_hash_index_update(&ctxt->copied, (uintptr_t) Z_COUNTED_P(src), dst);
 	}
+
+    return dst;
 }
 /* }}} */
 
 /* {{{ apc_copy_zval */
 PHP_APCU_API zval* apc_copy_zval(zval* dst, const zval* src, apc_context_t* ctxt)
 {
-    my_copy_zval(dst, src, ctxt);
-    return dst;
+    return my_copy_zval(dst, src, ctxt);
 }
 /* }}} */
 
@@ -1558,13 +1616,14 @@ PHP_APCU_API zval* apc_cache_store_zval(
         /* Maintain a list of zvals we've copied to properly handle recursive structures */
         zend_hash_init(&ctxt->copied, 16, NULL, NULL, 0);
         dst = apc_copy_zval(dst, src, ctxt);
+        /* remove from copied regardless if allocation failure */
         zend_hash_destroy(&ctxt->copied);
         ctxt->copied.nTableSize=0;
     } else {
         dst = apc_copy_zval(dst, src, ctxt);
     }
 
-	if (EG(exception)) {
+	if (dst == NULL || EG(exception)) {
 		return NULL;
 	}
 
@@ -1579,11 +1638,13 @@ PHP_APCU_API zval* apc_cache_fetch_zval(
         /* Maintain a list of zvals we've copied to properly handle recursive structures */
         zend_hash_init(&ctxt->copied, 16, NULL, NULL, 0);
         dst = apc_copy_zval(dst, src, ctxt);
+        /* remove from copied regardless if allocation failure */
         zend_hash_destroy(&ctxt->copied);
         ctxt->copied.nTableSize=0;
     } else {
         dst = apc_copy_zval(dst, src, ctxt);
     }
+
     return dst;
 }
 /* }}} */
@@ -1602,7 +1663,8 @@ PHP_APCU_API apc_cache_entry_t* apc_cach
 	/* set key for serializer */
 	ctxt->key = key;
 	
-    if(!apc_cache_store_zval(&entry->val, val, ctxt)) {
+    if (!apc_cache_store_zval(&entry->val, val, ctxt)) {
+        pool->pfree(pool, entry);
         return NULL;
     }
 
