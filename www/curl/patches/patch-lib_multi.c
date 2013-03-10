$NetBSD: patch-lib_multi.c,v 1.1 2013/03/10 13:21:05 obache Exp $

Fix NULL pointer reference when closing an unused multi handle.
(upstream commit da3fc1ee91de656a30f3a12de394bcba55119872)

--- lib/multi.c.orig	2013-02-05 22:01:40.000000000 +0000
+++ lib/multi.c
@@ -1773,10 +1773,12 @@ CURLMcode curl_multi_cleanup(CURLM *mult
     /* Close all the connections in the connection cache */
     close_all_connections(multi);
 
-    multi->closure_handle->dns.hostcache = multi->hostcache;
-    Curl_hostcache_clean(multi->closure_handle);
+    if(multi->closure_handle) {
+      multi->closure_handle->dns.hostcache = multi->hostcache;
+      Curl_hostcache_clean(multi->closure_handle);
 
-    Curl_close(multi->closure_handle);
+      Curl_close(multi->closure_handle);
+    }
     multi->closure_handle = NULL;
 
     Curl_hash_destroy(multi->sockhash);
