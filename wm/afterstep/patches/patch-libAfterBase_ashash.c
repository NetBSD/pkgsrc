$NetBSD: patch-libAfterBase_ashash.c,v 1.4 2021/07/11 12:13:17 bsiegert Exp $

Patch up gcc inline mess.

--- libAfterBase/ashash.c.orig	2013-05-01 13:34:11.000000000 +0000
+++ libAfterBase/ashash.c
@@ -39,7 +39,7 @@
 static ASHashItem*  deallocated_mem[DEALLOC_CACHE_SIZE+10] ;
 static unsigned int deallocated_used = 0 ;
 
-static inline void
+static void
 free_ashash_item( ASHashItem *item )
 {
 
@@ -533,7 +533,7 @@ remove_curr_hash_item (ASHashIterator * 
 		}
 }
 
-inline ASHashableValue
+ASHashableValue
 curr_hash_value (ASHashIterator * iterator)
 {
 	if (iterator)
@@ -544,7 +544,7 @@ curr_hash_value (ASHashIterator * iterat
 	return (ASHashableValue) ((char *)NULL);
 }
 
-inline void         *
+void         *
 curr_hash_data (ASHashIterator * iterator)
 {
 	if (iterator)
