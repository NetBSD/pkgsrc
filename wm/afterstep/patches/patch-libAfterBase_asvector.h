$NetBSD: patch-libAfterBase_asvector.h,v 1.3 2016/05/01 19:30:58 dholland Exp $

Patch up gcc inline mess.

--- libAfterBase/asvector.h.orig	2008-09-15 22:43:12.000000000 +0000
+++ libAfterBase/asvector.h
@@ -38,7 +38,7 @@ ASVector *append_vector( ASVector *v, vo
 /* returns index on success, -1 on failure */
 int vector_insert_elem( ASVector *v, void *data, size_t size, void *sibling, int before );
 int vector_relocate_elem (ASVector *v, unsigned int index, unsigned int new_index);
-inline size_t vector_find_data (ASVector *v, void *data );
+size_t vector_find_data (ASVector *v, void *data );
 int vector_find_elem( ASVector *v, void *data );
 /* returns 1 on success, 0 on failure */
 int vector_remove_elem( ASVector *v, void *data );
