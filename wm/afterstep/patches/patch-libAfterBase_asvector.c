$NetBSD: patch-libAfterBase_asvector.c,v 1.2 2013/04/07 10:36:54 cheusov Exp $

--- libAfterBase/asvector.c.orig	2008-12-02 22:35:37.000000000 +0000
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
@@ -210,7 +210,7 @@ LOCAL_DEBUG_OUT ("index = %d, offset = %
     }
 }
 
-inline void vector_move_data_down( ASVector *v, int index, int offset, int length )
+void vector_move_data_down( ASVector *v, int index, int offset, int length )
 {
     register int i ;
     /* word copying is usually faster then raw memory copying */
@@ -244,7 +244,7 @@ LOCAL_DEBUG_OUT ("index = %d, offset = %
     }
 }
 
-inline void vector_set_data( ASVector *v, void *data, int offset, int length)
+void vector_set_data( ASVector *v, void *data, int offset, int length)
 {
     register int i ;
     /* word copying is usually faster then raw memory copying */
