$NetBSD: patch-libAfterBase_asvector.c,v 1.1 2012/05/04 16:36:10 joerg Exp $

--- libAfterBase/asvector.c.orig	2012-05-04 14:36:35.000000000 +0000
+++ libAfterBase/asvector.c
@@ -126,7 +126,7 @@ LOCAL_DEBUG_CALLER_OUT("0x%lX, 0x%lX, %l
 
 /* finds index of the first element in the vector that is exactly matching specifyed
  * data */
-inline size_t vector_find_data( ASVector *v, void *data )
+size_t vector_find_data( ASVector *v, void *data )
 {
     register int i ;
     /* word copying is usually faster then raw memory copying */
@@ -170,7 +170,7 @@ inline size_t vector_find_data( ASVector
     return i;
 }
 
-inline void vector_move_data_up( ASVector *v, int index, int offset, int length )
+static void vector_move_data_up( ASVector *v, int index, int offset, int length )
 {
     register int i ;
     /* word copying is usually faster then raw memory copying */
