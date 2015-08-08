$NetBSD: patch-lib_transfer.c,v 1.1 2015/08/08 02:44:16 spz Exp $

part of
https://github.com/bagder/curl/commit/903b6e05565bf826b4194447864288642214b094
fixing
http://curl.haxx.se/mail/lib-2015-06/0122.html

--- lib/transfer.c.orig	2015-06-14 21:31:01.000000000 +0000
+++ lib/transfer.c
@@ -1315,6 +1315,11 @@ CURLcode Curl_pretransfer(struct Session
   Curl_safefree(data->info.wouldredirect);
   data->info.wouldredirect = NULL;
 
+  if(data->set.httpreq == HTTPREQ_PUT)
+    data->state.infilesize = data->set.filesize;
+  else
+    data->state.infilesize = data->set.postfieldsize;
+
   /* If there is a list of cookie files to read, do it now! */
   if(data->change.cookielist)
     Curl_cookie_loadfiles(data);
