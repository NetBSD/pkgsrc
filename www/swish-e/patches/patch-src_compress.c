$NetBSD: patch-src_compress.c,v 1.1 2017/02/09 00:18:01 joerg Exp $

--- src/compress.c.orig	2017-02-08 21:54:48.736189312 +0000
+++ src/compress.c
@@ -194,7 +194,7 @@ int     uncompress1(FILE * fp, int (*f_g
 
 /* same routine but this works with a memory forward buffer instead of file */
 /* it also increases the buffer pointer */
-int     uncompress2(unsigned char **buffer)
+int     swish_uncompress2(unsigned char **buffer)
 {
     int     _c;
     int     num = 0;
@@ -604,10 +604,10 @@ void uncompress_location_values(unsigned
     else
         (*frequency) |= (*flag) & 15;   /* Binary 00001111 */
 
-    *filenum = uncompress2(&p);
+    *filenum = swish_uncompress2(&p);
 
     if(! (*frequency))
-        *frequency = uncompress2(&p);
+        *frequency = swish_uncompress2(&p);
 
     *buf = p;
 }
@@ -656,7 +656,7 @@ void uncompress_location_positions(unsig
         }
 
         /* First position is always "as is" */
-        posdata[0] = (unsigned int)uncompress2(&p);
+        posdata[0] = (unsigned int)swish_uncompress2(&p);
 
         /* Check if positions where stored as two values per byte or the old "compress" style */
         if(flag & POS_4_BIT)
@@ -674,7 +674,7 @@ void uncompress_location_positions(unsig
         {
             for (i = 1; i < frequency; i++)
             {
-                tmp = uncompress2(&p);
+                tmp = swish_uncompress2(&p);
                 posdata[i] = (unsigned int)tmp;
             }
         }
@@ -974,8 +974,8 @@ void    remove_worddata_longs(unsigned c
     src = worddata;
 
     /* Jump over tfrequency and get first metaID */
-    tfrequency = uncompress2(&src);     /* tfrequency */
-    metaID = uncompress2(&src);     /* metaID */
+    tfrequency = swish_uncompress2(&src);     /* tfrequency */
+    metaID = swish_uncompress2(&src);     /* metaID */
     dst = src;
 
     while(1)
@@ -1006,7 +1006,7 @@ void    remove_worddata_longs(unsigned c
             break;   /* End of worddata */
 
         /* Get next metaID */
-        metaID = uncompress2(&src);
+        metaID = swish_uncompress2(&src);
         dst = compress3(metaID,dst);
     }
     /* Adjust to new size */
