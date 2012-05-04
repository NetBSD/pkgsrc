$NetBSD: patch-libAfterBase_ashash.c,v 1.1 2012/05/04 16:36:10 joerg Exp $

--- libAfterBase/ashash.c.orig	2012-05-04 14:37:05.000000000 +0000
+++ libAfterBase/ashash.c
@@ -503,7 +503,7 @@ remove_curr_hash_item (ASHashIterator * 
 		}
 }
 
-inline ASHashableValue
+ASHashableValue
 curr_hash_value (ASHashIterator * iterator)
 {
 	if (iterator)
@@ -514,7 +514,7 @@ curr_hash_value (ASHashIterator * iterat
 	return (ASHashableValue) ((char *)NULL);
 }
 
-inline void         *
+void         *
 curr_hash_data (ASHashIterator * iterator)
 {
 	if (iterator)
