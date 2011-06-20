$NetBSD: patch-apc__cache.c,v 1.1 2011/06/20 15:09:52 taca Exp $

- Fix pollution of the slots table with unoccupied slots from 
  repository r311376.

--- apc_cache.c.orig	2011-05-14 22:14:56.000000000 +0000
+++ apc_cache.c
@@ -1290,7 +1290,9 @@ zval* apc_cache_info(apc_cache_t* cache,
                 add_next_index_zval(list, link);
                 j++;
             }
-            add_next_index_long(slots, j);
+	    if(j != 0) {
+		add_next_index_long(slots, j);
+	    }
         }
 
         /* For each slot pending deletion */
