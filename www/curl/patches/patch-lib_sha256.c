$NetBSD: patch-lib_sha256.c,v 1.1 2026/06/07 18:03:46 adam Exp $

Allow building with nettle 4.0
https://github.com/curl/curl/pull/21169

--- lib/sha256.c.orig	2026-04-29 05:45:57.000000000 +0000
+++ lib/sha256.c
@@ -113,7 +113,8 @@ static void my_sha256_final(unsigned cha
 }
 
 #elif defined(USE_GNUTLS)
-#include <nettle/sha.h>
+#include <nettle/sha2.h>
+#include <nettle/version.h>
 
 typedef struct sha256_ctx my_sha256_ctx;
 
@@ -132,7 +133,11 @@ static void my_sha256_update(void *ctx,
 
 static void my_sha256_final(unsigned char *digest, void *ctx)
 {
+#if NETTLE_VERSION_MAJOR >= 4
+  sha256_digest(ctx, digest);
+#else
   sha256_digest(ctx, SHA256_DIGEST_SIZE, digest);
+#endif
 }
 
 #elif defined(USE_MBEDTLS) && \
