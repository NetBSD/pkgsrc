$NetBSD: patch-src_result__sort.c,v 1.1 2017/02/09 00:18:01 joerg Exp $

--- src/result_sort.c.orig	2017-02-08 21:48:55.316749633 +0000
+++ src/result_sort.c
@@ -262,7 +262,7 @@ int    *LoadSortedProps(IndexFILE * inde
 
         /* Unpack / decompress the numbers */
         for (j = 0; j < indexf->header.totalfiles; j++)
-            m->sorted_data[j] = uncompress2(&s);
+            m->sorted_data[j] = swish_uncompress2(&s);
 
         efree(buffer);
     }
