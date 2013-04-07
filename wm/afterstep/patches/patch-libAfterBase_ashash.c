$NetBSD: patch-libAfterBase_ashash.c,v 1.2 2013/04/07 10:36:54 cheusov Exp $

--- libAfterBase/ashash.c.orig	2008-03-17 22:42:32.000000000 +0000
+++ libAfterBase/ashash.c
@@ -39,7 +39,7 @@
 static ASHashItem*  deallocated_mem[DEALLOC_CACHE_SIZE+10] ;
 static unsigned int deallocated_used = 0 ;
 
-static inline void 
+static void 
 free_ashash_item( ASHashItem *item ) 
 {
 
@@ -531,7 +531,7 @@ remove_curr_hash_item (ASHashIterator * 
 		}
 }
 
-inline ASHashableValue
+ASHashableValue
 curr_hash_value (ASHashIterator * iterator)
 {
 	if (iterator)
@@ -542,7 +542,7 @@ curr_hash_value (ASHashIterator * iterat
 	return (ASHashableValue) ((char *)NULL);
 }
 
-inline void         *
+void         *
 curr_hash_data (ASHashIterator * iterator)
 {
 	if (iterator)
