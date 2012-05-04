$NetBSD: patch-libAfterBase_asvector.h,v 1.1 2012/05/04 16:36:10 joerg Exp $

--- libAfterBase/asvector.h.orig	2012-05-04 14:36:33.000000000 +0000
+++ libAfterBase/asvector.h
@@ -38,7 +38,7 @@ ASVector *append_vector( ASVector *v, vo
 /* returns index on success, -1 on failure */
 int vector_insert_elem( ASVector *v, void *data, size_t size, void *sibling, int before );
 int vector_relocate_elem( ASVector *v, void *data, unsigned int new_index );
-inline size_t vector_find_data( ASVector *v, void *data );
+size_t vector_find_data( ASVector *v, void *data );
 int vector_find_elem( ASVector *v, void *data );
 /* returns 1 on success, 0 on failure */
 int vector_remove_elem( ASVector *v, void *data );
