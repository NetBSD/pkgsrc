$NetBSD: patch-lib_curl__threads.c,v 1.1 2025/10/24 04:01:11 riastradh Exp $

Disable pthread_cancel.
https://github.com/curl/curl/issues/18532
https://eissing.org/icing/posts/rip_pthread_cancel/
https://gnats.NetBSD.org/59720

--- lib/curl_threads.c.orig	2025-09-10 05:43:43.000000000 +0000
+++ lib/curl_threads.c
@@ -106,7 +106,7 @@ int Curl_thread_join(curl_thread_t *hnd)
  * - this is a -fsanitize=thread build
  *   (clang sanitizer reports false positive when functions to not return)
  */
-#if defined(PTHREAD_CANCEL_ENABLE) && !defined(__FreeBSD__)
+#if 0 && defined(PTHREAD_CANCEL_ENABLE) && !defined(__FreeBSD__)
 #if defined(__has_feature)
 #  if !__has_feature(thread_sanitizer)
 #define USE_PTHREAD_CANCEL
