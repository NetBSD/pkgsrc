$NetBSD: patch-editkit_edit.c,v 1.1 2022/12/09 14:13:00 vins Exp $
 
Prevent warnings about size mismatch in -
pointer to integer conversion.

--- editkit/edit.c.orig	2006-09-11 11:29:16.000000000 +0000
+++ editkit/edit.c
@@ -28,6 +28,8 @@ void prrec(U_REC* undp, char indicator)
 }
 */
 
+# include <stdint.h>
+
 /* get true x co-ord for char at 'pos' */
 int get_tru(char* pos)
 {
@@ -106,7 +108,7 @@ char * realloc_buffer(int mode)
 			ptr = realloc(unbuf, (size_t)i);
 			if (ptr) {
 				umax += UMAX;
-				i = (int)ptr - (int)unbuf;
+				i = (int)(uintptr_t)ptr - (int)(uintptr_t)unbuf;
 				unbuf = ptr;
 				undop = (void*)undop+i;
 				undosp = (void*)undosp+i;
@@ -139,7 +141,7 @@ U_REC* new_undo(char *pos, int len)
 		tmp = (void *) unbuf;
 	}
 
-	tmp->link = (unsigned int)undosp - (unsigned int)unbuf;
+	tmp->link = (unsigned int)(uintptr_t)undosp - (unsigned int)(uintptr_t)unbuf;
 	tmp->pos = pos - edbuf;
 	tmp->length = 0;
 	return tmp;
@@ -1721,9 +1723,9 @@ void doblockr()
 		else
 			*bb_end++ = c;
 		if (bb_end >= bb+bmax) {
-			d = (int)bb;
+			d = (int)(uintptr_t)bb;
 			realloc_buffer(1);
-			d = (int)bb - d;
+			d = (int)(uintptr_t)bb - d;
 			col += d;
 			bb_end += d;
 		}
