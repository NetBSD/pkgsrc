$NetBSD: patch-libAfterBase_ashash.h,v 1.1 2012/05/04 16:36:10 joerg Exp $

--- libAfterBase/ashash.h.orig	2012-05-04 14:37:03.000000000 +0000
+++ libAfterBase/ashash.h
@@ -133,8 +133,8 @@ unsigned long list_hash_items (ASHashTab
 
 Bool start_hash_iteration (ASHashTable * hash, ASHashIterator * iterator);
 Bool next_hash_item (ASHashIterator * iterator);
-inline ASHashableValue curr_hash_value (ASHashIterator * iterator);
-inline void *curr_hash_data (ASHashIterator * iterator);
+ASHashableValue curr_hash_value (ASHashIterator * iterator);
+void *curr_hash_data (ASHashIterator * iterator);
 void remove_curr_hash_item (ASHashIterator * iterator, Bool destroy);
 
 
