$NetBSD: patch-lib_md5.c,v 1.1 2026/06/07 18:03:46 adam Exp $

Allow building with nettle 4.0
https://github.com/curl/curl/pull/21169

--- lib/md5.c.orig	2026-04-29 05:45:57.000000000 +0000
+++ lib/md5.c
@@ -47,6 +47,7 @@
 
 #ifdef USE_GNUTLS
 #include <nettle/md5.h>
+#include <nettle/version.h>
 
 typedef struct md5_ctx my_md5_ctx;
 
@@ -64,7 +65,11 @@ static void my_md5_update(void *ctx,
 
 static void my_md5_final(unsigned char *digest, void *ctx)
 {
+#if NETTLE_VERSION_MAJOR >= 4
+  md5_digest(ctx, digest);
+#else
   md5_digest(ctx, 16, digest);
+#endif
 }
 
 #elif defined(USE_OPENSSL) && \
