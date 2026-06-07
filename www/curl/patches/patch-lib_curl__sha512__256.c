$NetBSD: patch-lib_curl__sha512__256.c,v 1.1 2026/06/07 18:03:46 adam Exp $

Allow building with nettle 4.0
https://github.com/curl/curl/pull/21169

--- lib/curl_sha512_256.c.orig	2026-04-29 05:45:57.000000000 +0000
+++ lib/curl_sha512_256.c
@@ -75,7 +75,8 @@
 #endif
 
 #if !defined(HAS_SHA512_256_IMPLEMENTATION) && defined(USE_GNUTLS)
-#  include <nettle/sha.h>
+#  include <nettle/sha2.h>
+#  include <nettle/version.h>
 #  ifdef SHA512_256_DIGEST_SIZE
 #    define USE_GNUTLS_SHA512_256           1
 #  endif
@@ -281,8 +282,12 @@ static CURLcode Curl_sha512_256_finish(u
 {
   Curl_sha512_256_ctx * const ctx = (Curl_sha512_256_ctx *)context;
 
+#if NETTLE_VERSION_MAJOR >= 4
+  sha512_256_digest(ctx, (uint8_t *)digest);
+#else
   sha512_256_digest(ctx,
                     (size_t)CURL_SHA512_256_DIGEST_SIZE, (uint8_t *)digest);
+#endif
 
   return CURLE_OK;
 }
