$NetBSD: patch-lib_multi.c,v 1.5 2026/05/15 12:32:20 kikadf Exp $

* Apply upstream commit to fix high cpu usage
  https://github.com/curl/curl/commit/2a2104f3cff44bb28bb570a093be52bbeeed8f23

--- lib/multi.c.orig	2026-05-15 14:06:57.225055741 +0200
+++ lib/multi.c
@@ -2479,6 +2479,11 @@ static CURLMcode multi_runsingle(struct 
   Curl_uint32_bset_remove(&multi->dirty, data->mid);
 
   if(data == multi->admin) {
+#ifdef ENABLE_WAKEUP
+    /* Consume any pending wakeup signals before processing.
+     * This is necessary for event based processing. See #21547 */
+    (void)Curl_wakeup_consume(multi->wakeup_pair, TRUE);
+#endif
 #ifdef USE_RESOLV_THREADED
     Curl_async_thrdd_multi_process(multi);
 #endif
