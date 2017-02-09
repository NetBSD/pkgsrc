$NetBSD: patch-src_search.c,v 1.1 2017/02/09 00:18:01 joerg Exp $

--- src/search.c.orig	2017-02-08 21:48:51.513187901 +0000
+++ src/search.c
@@ -1719,14 +1719,14 @@ static RESULT_LIST *getfileinfo(DB_RESUL
         // buffer structure = <tfreq><metaID><delta to next meta>
 
         /* Get the data of the word */
-        tfrequency = uncompress2(&s); /* tfrequency - number of files with this word */
+        tfrequency = swish_uncompress2(&s); /* tfrequency - number of files with this word */
 
         /* Now look for a correct Metaname */
-        curmetaID = uncompress2(&s);
+        curmetaID = swish_uncompress2(&s);
 
         while (curmetaID)
         {
-            metadata_length = uncompress2(&s);
+            metadata_length = swish_uncompress2(&s);
             
             if (curmetaID >= metaID)
                 break;
@@ -1738,7 +1738,7 @@ static RESULT_LIST *getfileinfo(DB_RESUL
             if(s == (buffer + sz_buffer))
                 break; /* exit if no more meta data */
 
-            curmetaID = uncompress2(&s);
+            curmetaID = swish_uncompress2(&s);
         }
 
         if (curmetaID == metaID) /* found a matching meta value */
