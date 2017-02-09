$NetBSD: patch-src_db__native.c,v 1.1 2017/02/09 00:18:01 joerg Exp $

--- src/db_native.c.orig	2017-02-08 21:49:04.614639531 +0000
+++ src/db_native.c
@@ -1595,7 +1595,7 @@ long    DB_ReadWordData_Native(sw_off_t 
 
     *worddata = buf = WORDDATA_Get(DB->worddata,wordID,data_size);
     /* Get saved_bytes and adjust data_size */
-    *saved_bytes = uncompress2(&buf);
+    *saved_bytes = swish_uncompress2(&buf);
     *data_size -= (buf - (*worddata));
     /* Remove saved_bytes from buffer
     ** We need to use memmove because data overlaps */
