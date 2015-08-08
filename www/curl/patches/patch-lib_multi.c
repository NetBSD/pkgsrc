$NetBSD: patch-lib_multi.c,v 1.3 2015/08/08 02:44:16 spz Exp $

part of
https://github.com/bagder/curl/commit/903b6e05565bf826b4194447864288642214b094
fixing
http://curl.haxx.se/mail/lib-2015-06/0122.html

--- lib/multi.c.orig	2015-06-15 21:14:25.000000000 +0000
+++ lib/multi.c
@@ -402,11 +402,6 @@ CURLMcode curl_multi_add_handle(CURLM *m
   /* Point to the multi's connection cache */
   data->state.conn_cache = &multi->conn_cache;
 
-  if(data->set.httpreq == HTTPREQ_PUT)
-    data->state.infilesize = data->set.filesize;
-  else
-    data->state.infilesize = data->set.postfieldsize;
-
   /* This adds the new entry at the 'end' of the doubly-linked circular
      list of SessionHandle structs to try and maintain a FIFO queue so
      the pipelined requests are in order. */
