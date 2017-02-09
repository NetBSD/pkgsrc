$NetBSD: patch-src_merge.c,v 1.1 2017/02/09 00:18:01 joerg Exp $

--- src/merge.c.orig	2017-02-08 21:48:57.570631072 +0000
+++ src/merge.c
@@ -221,12 +221,12 @@ void merge_indexes( SWISH *sw_input, SWI
 
                         /* Now, parse word's data */
                         s = worddata;
-                        tmpval = uncompress2(&s);     /* tfrequency */
-                        metaID = uncompress2(&s);     /* metaID */
+                        tmpval = swish_uncompress2(&s);     /* tfrequency */
+                        metaID = swish_uncompress2(&s);     /* metaID */
 
                         if (metaID)
                         {
-                            metadata_length = uncompress2(&s);
+                            metadata_length = swish_uncompress2(&s);
                         }
 
                         filenum = 0;
@@ -274,8 +274,8 @@ void merge_indexes( SWISH *sw_input, SWI
                             if ( metadata_length == (s - start))
                             {
                                 filenum = 0;
-                                metaID = uncompress2(&s);
-                                metadata_length = uncompress2(&s);
+                                metaID = swish_uncompress2(&s);
+                                metadata_length = swish_uncompress2(&s);
                                 start = s;
                             }
                         }
